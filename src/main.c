#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/util.h"
#include "../include/element.h"
#include "../include/edge.h"

int main(int argc, char const *argv[])
{
    char *input_file = strdup(argv[1]);
    char *output_file = strdup(argv[3]);
    int groups = atoi(argv[2]);

    FILE * file = fopen(input_file,"r");
    int element_set_size = get_lines_amount(file);
    int dimension = get_dimension(file);
    int graph_size = calculate_graph_size(element_set_size);

    Element ** elements = read_elements(file, element_set_size, dimension);
    Edge ** graph = generate_graph(elements, graph_size, element_set_size, dimension);    

    printf("dimension = %d\n", dimension);
    printf("graph size = %d\n", graph_size);

    qsort(graph, graph_size, sizeof(Edge*), edge_comparator);
    print_graph(graph, graph_size);
    
    // print_elements(elements, element_set_size, dimension);

    // clock_t sort_time_start, sort_time_end;
    // sort_time_start = clock();    
    // sort_time_end = clock();

    // double sort_time_seconds = ((double)sort_time_end - sort_time_start)/CLOCKS_PER_SEC;
    // printf("sort time = %lf\n", sort_time_seconds);

    free(input_file);
    free(output_file);
    
    return 0;
}
