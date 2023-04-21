#ifndef util_h
#define util_h
#include "edge.h"
#include "element.h"
#include "priority_queue.h"

int get_lines_amount(FILE *file);

short get_dimension(FILE *file);

double distance(double *e1, double *e2, int dim);

int calculate_graph_size(int root);

Element **read_elements(FILE *file, int set_size, int dimension);

Edge **generate_graph(Element **elements, int graph_size, int set_size, int dimension);

void print_elements(Element **elements, int set_size, int dimension);

void print_graph(Edge **graph, int graph_size);

int *union_find_kruskal(Element **set, int set_size, Edge **graph, int graph_size, int dimension, int groups_amount);

PQueue **generate_groups(Element **set, int set_size, int *id_vector, int groups);

#endif
