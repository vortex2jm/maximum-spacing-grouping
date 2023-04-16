#include <stdio.h>
#include <stdlib.h>
#include "../include/element.h"

struct element
{
    int id;
    char * name;
    double * coordinates;
};

Element * init_element(int id, char * name, double * coordinates){
    Element * element = malloc(sizeof(Element));
    element->coordinates = coordinates;
    element->id = id;
    element->name = name;
    return element;
}

double * get_element_coordinates(Element * element){
    return element->coordinates;
}

void print_element(Element *element, int dimension)
{
    printf("%s\n", element->name);
    for (short i = 0; i < dimension; i++)
    {
        printf("%.14lf\n", element->coordinates[i]);
    }
}
