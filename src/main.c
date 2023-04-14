#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/graph.h"
#include "../include/set.h"
#include "../include/util.h"

int main(int argc, char const *argv[])
{
    char *input_file = strdup(argv[1]);
    char *output_file = strdup(argv[3]);
    int groups = atoi(argv[2]);

    ElementSet *set = init_set(input_file);
    Graph *graph = init_graph(set);

    // clock_t sort_time_start, sort_time_end;
    // sort_time_start = clock();
    
    sort_graph(graph);
    
    // sort_time_end = clock();

    // double sort_time_seconds = ((double)sort_time_end - sort_time_start)/CLOCKS_PER_SEC;
    // printf("sort time = %lf\n", sort_time_seconds);
    // print_graph(graph);
    // print_set(set);

    end_graph(graph);
    end_set(set);

    free(input_file);
    free(output_file);
    
    return 0;
}
