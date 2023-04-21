#ifndef element_h
#define element_h

typedef struct element Element;

Element *init_element(int id, char *name, double *coordinates);

int get_element_id(Element *element);

char *get_element_name(Element *element);

double *get_element_coordinates(Element *element);

void print_element(Element *element);

#endif
