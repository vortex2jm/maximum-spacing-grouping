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

int *union_find_kruskal(Element **set, int set_size, Edge **graph, int graph_size, int dimension, int groups_amount);

PQueue **generate_groups(Element **set, int set_size, int *id_vector, int groups);

void end_set(Element ** set, int set_size);

void end_graph(Edge ** graph, int graph_size);

void end_groups(PQueue ** groups, int groups_amount);

void generate_output(PQueue ** groups, int groups_amount, char * out_file_name);

#endif
