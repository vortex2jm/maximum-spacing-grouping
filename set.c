#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "util.h"

// Structures
typedef struct element
{
    int id;
    char *name;
    double *coordinates;
} Element;

struct element_set
{
    Element **element;
    int size;
    int dimension;
};

void print_element(Element *element, int dimension);
void delete_element(Element *element);

//================================================================//
ElementSet *init_set(char *file_name)
{
    ElementSet * set = malloc(sizeof(ElementSet));

    FILE *file = fopen(file_name, "r");
    int lines_amount = get_lines_amount(file);
    short dimension = get_dimension(file);

    set->element = malloc(sizeof(Element *) * (lines_amount));
    set->size = (lines_amount);
    set->dimension = dimension;

    char line[2000];
    int i = 0;
    while (!feof(file))
    {
        set->element[i] = malloc(sizeof(Element));
        set->element[i]->coordinates = malloc(sizeof(double) * dimension);
        set->element[i]->id = i;

        fscanf(file, "%[^\n]\n", line);
        char *tk = strtok(line, ",");

        short j = 0;
        while (tk != NULL)
        {
            if (!j)
            {
                set->element[i]->name = strdup(tk);
            }
            else
            {
                sscanf(tk, "%lf", &set->element[i]->coordinates[j - 1]);
            }
            tk = strtok(NULL, ",");
            j++;
        }
        i++;
    }
    fclose(file);
    return set;
}

void print_set(ElementSet *set)
{
    for (int i = 0; i < set->size; i++)
    {
        print_element(set->element[i], set->dimension);
    }
}

int get_set_size(ElementSet * set){
    if(set)
        return set->size;
}

int get_set_dimension(ElementSet * set){
    if(set)
        return set->dimension;
}

void end_set(ElementSet *set)
{
    if (set)
    {
        if (set->element)
        {
            for (int x = 0; x < set->size; x++)
            {
                if (set->element[x])
                    delete_element(set->element[x]);
            }
            free(set->element);
        }
        free(set);
    }
}

double * generate_edges(ElementSet * set, int graph_size){
    double * graph = malloc(sizeof(double) * graph_size);
    int index=0;
    for(int x=0; x<set->size-1;x++){
        for(int y=x+1; y<set->size;y++){
            graph[index] = distance(set->element[x]->coordinates, set->element[y]->coordinates, set->dimension);
            index++;
        }
    }
    return graph;
}

//ELEMENTS================================================================//
void delete_element(Element *element)
{
    if (element)
    {
        if (element->name)
            free(element->name);
        if (element->coordinates)
            free(element->coordinates);
        free(element);
    }
}

void print_element(Element *element, int dimension)
{
    printf("%s\n", element->name);
    for (short i = 0; i < dimension; i++)
    {
        printf("%.14lf\n", element->coordinates[i]);
    }
}
