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
    int groups_amount = atoi(argv[2]);

    FILE *file = fopen(input_file, "r");
    int element_set_size = get_lines_amount(file);
    int dimension = get_dimension(file);
    int graph_size = calculate_graph_size(element_set_size);

    Element **elements = read_elements(file, element_set_size, dimension);
    Edge **graph = generate_graph(elements, graph_size, element_set_size, dimension);

    qsort(graph, graph_size, sizeof(Edge *), edge_comparator);

    int *id_vector = union_find_kruskal(elements, element_set_size, graph, graph_size, dimension, groups_amount);

    PQueue **groups = generate_groups(elements, element_set_size, id_vector, groups_amount);
    generate_output(groups, groups_amount, output_file);

    fclose(file);
    free(id_vector);
    free(input_file);
    free(output_file);
    end_graph(graph, graph_size);
    end_groups(groups, groups_amount);
    end_set(elements, element_set_size);

    return 0;
}
