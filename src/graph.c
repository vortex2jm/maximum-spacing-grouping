#include <stdio.h>
#include <stdlib.h>
#include "../include/graph.h"
#include "../include/util.h"

struct graph{
    double * elements;
    int size;
};

Graph * init_graph(ElementSet * set){
    int graph_size = calculate_graph_size(get_set_size(set));

    Graph * graph = malloc(sizeof(Graph));
    graph->size = graph_size;
    graph->elements = generate_edges(set, graph_size);

    return graph;
}

int graph_comparator(const void* e1, const void * e2){
    if(*(double*)e1 > *(double*)e2)
        return 1;
    if(*(double*)e1 < *(double*)e2)
        return -1;
    return 0;
}

void sort_graph(Graph * graph){
    qsort(graph->elements, graph->size, sizeof(double), graph_comparator);    
}

void print_graph(Graph * graph){
    if(graph){
        printf("GRAPH SIZE = %d\n", graph->size);
        for(int x=0; x<graph->size;x++){
            printf("%lf\n", graph->elements[x]);
        }
    }       
}

void end_graph(Graph * graph){
    if(graph){
        if(graph->elements)
            free(graph->elements);
        free(graph);
    }
}
