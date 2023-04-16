#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../include/util.h"
#include "../include/element.h"
#include "../include/edge.h"
#include <string.h>

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
double distance(double* e1, double* e2, int dim){
    double sum=0;
    for(int x=0; x<dim; x++){
        sum += pow((e1[x] - e2[x]),2);
    }
    return sqrt(sum);
}

//=================================//
int calculate_graph_size(int root){
    if(root==2) return 1;
    return (root-1) + calculate_graph_size(root-1);
}

//=================================================================//
Element ** read_elements(FILE * file, int set_size, int dimension){
    Element ** elements = malloc(sizeof(Element*)*set_size);

    int i=0;
    char line[2000], *name;

    while(!feof(file)){
        double * coordinates = malloc(sizeof(double)*dimension);
        
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
        
        // print_element(elements[i], dimension);
        
        i++;
    }
    return elements;
}

//======================================================================================// 
Edge ** generate_graph(Element ** elements, int graph_size, int set_size, int dimension){
    
    Edge ** graph = malloc(sizeof(Edge*) * graph_size);

    int index=0;
    for(int x=0; x<set_size-1;x++){
        for(int y=x+1; y<set_size;y++){
            graph[index] = init_edge(
                distance(
                    get_element_coordinates(elements[x]), 
                    get_element_coordinates(elements[y]),
                    dimension
                ),
                elements[x],
                elements[y]
            );
            index++;
        }
    }
    return graph;
}

//===================================================================//
void print_elements(Element ** elements, int set_size, int dimension){
    if(elements){
        for(int x=0; x<set_size; x++){
            print_element(elements[x], dimension);
        }
    }
}

//==============================================//
void print_graph(Edge ** graph, int graph_size){
    if(graph){
        for(int x=0; x<graph_size; x++){
            print_edge(graph[x]);
        }
    }
}
