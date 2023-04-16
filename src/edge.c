#include <stdio.h>
#include <stdlib.h>
#include "../include/edge.h"
#include "../include/element.h"

struct edge
{
    double distance;
    Element * e1;
    Element * e2;
};

Edge * init_edge(double distance, Element * e1, Element * e2){
    Edge * edge = malloc(sizeof(Edge));
    edge->distance = distance;
    edge->e1 = e1;
    edge->e2 = e2;
    return edge;
}

double get_edge_distance(Edge * edge){
    return edge->distance;
}

void print_edge(Edge * edge){
    printf("%lf\n", edge->distance);
}

int edge_comparator(const void * e1, const void * e2)
{
    Edge * (*a) = (Edge**)e1;
    Edge * (*b) = (Edge**)e2;
    if((*a)->distance > (*b)->distance){
        return 1;
    }
    if((*a)->distance > (*b)->distance)
        return -1;
    return 0;
}