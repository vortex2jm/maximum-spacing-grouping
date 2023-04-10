#ifndef element_h
#define element_h

typedef struct element_set ElementSet;

ElementSet *init_set();

unsigned short read_elements(char *file_name, ElementSet *elements);

void print_set(ElementSet *set);

void end_set(ElementSet *set);

#endif
