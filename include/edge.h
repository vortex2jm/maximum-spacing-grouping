#ifndef edge_h
#define edge_h
#include "element.h"

typedef struct edge Edge;

Edge * init_edge(double distance, Element * e1, Element * e2);

int edge_comparator(const void* e1, const void * e2);

double get_edge_distance(Edge * edge);

Element * get_edge_e1(Edge * edge);

Element * get_edge_e2(Edge * edge);

void print_edge(Edge * edge);

void end_edge(Edge * edge);

#endif
