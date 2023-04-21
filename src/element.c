#include <stdio.h>
#include <stdlib.h>
#include "../include/element.h"

struct element
{
    int id;
    char *name;
    double *coordinates;
};

//==============================================================//
Element *init_element(int id, char *name, double *coordinates)
{
    Element *element = malloc(sizeof(Element));
    element->coordinates = coordinates;
    element->id = id;
    element->name = name;
    return element;
}

//=================================================//
double *get_element_coordinates(Element *element)
{
    return element->coordinates;
}

//===================================//
int get_element_id(Element *element)
{
    return element->id;
}

//===================================//
char *get_element_name(Element *element)
{
    return element->name;
}

//=================================================//
void print_element(Element *element)
{
    printf("%s", element->name);
}
