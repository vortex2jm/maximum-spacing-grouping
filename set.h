#ifndef element_h
#define element_h

typedef struct element_set ElementSet;

ElementSet* init_set(char *file_name);

int get_set_size(ElementSet * set);

int get_set_dimension(ElementSet * set);

void print_set(ElementSet *set);

void end_set(ElementSet *set);

double * generate_edges(ElementSet * set, int size);

#endif
