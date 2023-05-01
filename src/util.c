#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "../include/util.h"
#include "../include/element.h"
#include "../include/edge.h"

short get_dimension(FILE *file);
int get_lines_amount(FILE *file);
int calculate_graph_size(int root);
int dc_find_root(int e, int *vector);
void print_graph(Edge **graph, int graph_size);
double distance(double *e1, double *e2, int dim);
int dc_union(int e1, int e2, int *vector, int *weight);
Element **read_elements(FILE *file, int set_size, int dimension);
void print_elements(Element **elements, int set_size, int dimension);
Edge **generate_graph(Element **elements, int graph_size, int set_size, int dimension);
int *union_find_kruskal(Element **set, int set_size, Edge **graph, int graph_size, int dimension, int groups_amount);

//=============================//
int get_lines_amount(FILE *file)
{
    int amount = 0;
    for (char c = fgetc(file); c != EOF; c = fgetc(file))
    {
        if (c == '\n')
        {
            amount++;
        }
    }
    fseek(file, 0, SEEK_SET);
    return amount;
}

//=============================//
short get_dimension(FILE *file)
{
    char line[2000];
    fscanf(file, "%[^\n]\n", line);
    char *tk = strtok(line, ",");
    short count = 0;
    while (tk != NULL)
    {
        count++;
        tk = strtok(NULL, ",");
    }
    fseek(file, 0, SEEK_SET);
    return count - 1;
}

//==============================================//
double distance(double *e1, double *e2, int dim)
{
    double sum = 0;
    for (int x = 0; x < dim; x++)
    {
        sum += pow((e1[x] - e2[x]), 2);
    }
    return sqrt(sum);
}

//=================================//
int calculate_graph_size(int root)
{
    return ((root * (root-1))/2);
}

//=================================================================//
Element **read_elements(FILE *file, int set_size, int dimension)
{
    Element **elements = malloc(sizeof(Element *) * set_size);

    int i = 0;
    char line[2000], *name;

    while (!feof(file))
    {
        double *coordinates = malloc(sizeof(double) * dimension);

        fscanf(file, "%[^\n]\n", line);
        char *tk = strtok(line, ",");
        short j = 0;

        while (tk != NULL)
        {
            if (!j)
            {
                name = strdup(tk);
            }
            else
            {
                sscanf(tk, "%lf", &coordinates[j - 1]);
            }
            tk = strtok(NULL, ",");
            j++;
        }
        elements[i] = init_element(i, name, coordinates);
        i++;
    }
    return elements;
}

//======================================================================================//
Edge **generate_graph(Element **elements, int graph_size, int set_size, int dimension)
{

    Edge **graph = malloc(sizeof(Edge *) * graph_size);

    int index = 0;
    for (int x = 0; x < set_size - 1; x++)
    {
        for (int y = x + 1; y < set_size; y++)
        {
            graph[index] = init_edge(
                distance(
                    get_element_coordinates(elements[x]),
                    get_element_coordinates(elements[y]),
                    dimension),
                elements[x],
                elements[y]);
            index++;
        }
    }
    return graph;
}

//=================================================================================================================//
int *union_find_kruskal(Element **set, int set_size, Edge **graph, int graph_size, int dimension, int groups_amount)
{

    int *id_vector = malloc(sizeof(int) * set_size);
    for (int x = 0; x < set_size; x++)
        id_vector[x] = x;

    int *weight_vector = malloc(sizeof(int) * set_size);
    for (int x = 0; x < set_size; x++)
        weight_vector[x] = 1;

    Element *e1, *e2;
    int mst_limit = set_size - 1 - (groups_amount - 1), mst_count = 0;

    for (int x = 0; x < graph_size; x++)
    {

        if (mst_count == mst_limit)
            break;

        e1 = get_edge_e1(graph[x]);
        e2 = get_edge_e2(graph[x]);

        mst_count += dc_union(
            get_element_id(e1),
            get_element_id(e2),
            id_vector,
            weight_vector);
    }

    free(weight_vector);
    return id_vector;
}

//================================================//
PQueue **generate_groups(Element **set, int set_size, int *id_vector, int groups)
{

    int *rc_roots = malloc(sizeof(int) * groups);
    int roots_index = 0;

    for (int x = 0; x < set_size; x++)
    {
        if (id_vector[x] == x)
        {
            rc_roots[roots_index] = x;
            roots_index++;
        }
    }

    PQueue **queues = malloc(sizeof(PQueue *) * groups);
    for (int x = 0; x < groups; x++)
    {
        queues[x] = init_queue();
    }

    for (int x = 0; x < set_size; x++)
    {
        for (int y = 0; y < groups; y++)
        {
            if (dc_find_root(x, id_vector) == rc_roots[y])
            {
                q_push(queues[y], set[x]);
            }
        }
    }

    qsort(queues, groups, sizeof(PQueue *), queue_comparator);
    free(rc_roots);

    return queues;
}

//===================================//
int dc_find_root(int e, int *vector)
{
    while (e != vector[e])
    {
        vector[e] = vector[vector[e]];
        e = vector[e];
    }
    return e;
}

//=====================================================//
int dc_union(int e1, int e2, int *vector, int *weight)
{
    int x = dc_find_root(e1, vector);
    int y = dc_find_root(e2, vector);

    if (x == y)
        return 0;
    if (weight[x] < weight[y])
    {
        vector[x] = y;
        weight[y] += weight[x];
        return 1;
    }
    vector[y] = x;
    weight[x] += weight[y];
    return 1;
}

void end_set(Element ** set, int set_size){
    if(set){
        for(int x=0; x<set_size; x++){
            if(set[x]){
                end_element(set[x]);
            }
        }
        free(set);
    }
}

void end_graph(Edge ** graph, int graph_size){
    if(graph){
        for(int x=0; x<graph_size; x++){
            if(graph[x]){
                end_edge(graph[x]);
            }
        }
        free(graph);
    }
}

void end_groups(PQueue ** groups, int groups_amount){
    if(groups){
        for(int x=0; x<groups_amount; x++){
            if(groups[x]){
                end_queue(groups[x]);
            }
        }
        free(groups);
    }
}

void generate_output(PQueue ** groups, int groups_amount, char * out_file_name){
    FILE * file = fopen(out_file_name, "w");
    for(int x=0; x<groups_amount; x++){
        print_queue(groups[x], file);
    }
    fclose(file);
}
