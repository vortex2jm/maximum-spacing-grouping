#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "set.h"
#include "util.h"

int main(int argc, char const *argv[])
{
    char *input_file = strdup(argv[1]);
    char *output_file = strdup(argv[3]);
    int groups = atoi(argv[2]);

    ElementSet *set = init_set(input_file);
    Graph *graph = init_graph(set);

    print_graph(graph);
    print_set(set);

    end_graph(graph);
    end_set(set);

    free(input_file);
    free(output_file);
    
    return 0;
}
