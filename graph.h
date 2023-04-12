#ifndef graph_h
#define graph_h
#include "set.h"

typedef struct graph Graph;

Graph * init_graph(ElementSet * set);

void print_graph(Graph * graph);

void end_graph(Graph * graph);

#endif
