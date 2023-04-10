#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "element.h"
#include "util.h"

// Structures
typedef struct element
{
    char *id;
    double *coordinates;
    short dimensions;
} Element;

struct element_set
{
    Element **element;
    int size;
};

// Functions======================================================//
ElementSet *init_set()
{
    ElementSet *set = malloc(sizeof(ElementSet));
    set->element = NULL;
    set->size = 0;
    return set;
}

//================================================================//
unsigned short read_elements(char *file_name, ElementSet *set)
{

    FILE *file = fopen(file_name, "r");
    int lines_amount = get_lines_amount(file);
    short dimensions = get_dimensions(file);

    set->element = malloc(sizeof(Element *) * (lines_amount));
    set->size = (lines_amount);

    char line[2000];
    int i = 0;
    while (!feof(file))
    {

        set->element[i] = malloc(sizeof(Element));
        set->element[i]->coordinates = malloc(sizeof(double) * dimensions);
        set->element[i]->dimensions = dimensions;

        fscanf(file, "%[^\n]\n", line);
        char *tk = strtok(line, ",");

        short j = 0;
        while (tk != NULL)
        {
            if (!j)
            {
                set->element[i]->id = strdup(tk);
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
    return dimensions;
}

//================================================================//
void print_element(Element *element)
{
    printf("%s\n", element->id);
    for (short i = 0; i < element->dimensions; i++)
    {
        printf("%.14lf\n", element->coordinates[i]);
    }
}

void print_set(ElementSet *set)
{
    for (int i = 0; i < set->size; i++)
    {
        print_element(set->element[i]);
    }
}

//================================================================//
void delete_element(Element *element)
{
    if (element)
    {
        if (element->id)
            free(element->id);
        if (element->coordinates)
            free(element->coordinates);
        free(element);
    }
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
