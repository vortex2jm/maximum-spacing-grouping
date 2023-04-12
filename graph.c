#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct graph{
    double * elements;
    int size;
};

Graph * init_graph(ElementSet * set){
    int graph_size=0;

    // Combination 2x2
    for(int x=get_set_size(set)-1; x>0;x--){
        graph_size+=x;
    }

    Graph * graph = malloc(sizeof(Graph));
    graph->size = graph_size;
    graph->elements = generate_edges(set, graph_size);

    return graph;
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
