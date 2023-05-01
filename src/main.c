// A parte do código comentada foi destinada a medição dos tempos de execução //
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

    // clock_t read_start = clock();
    Element **elements = read_elements(file, element_set_size, dimension);
    // clock_t read_end = clock();

    // clock_t distance_calc_start = clock();
    Edge **graph = generate_graph(elements, graph_size, element_set_size, dimension);
    // clock_t distance_calc_end = clock();

    // clock_t sort_edge_start = clock();
    qsort(graph, graph_size, sizeof(Edge *), edge_comparator);
    // clock_t sort_edge_end = clock();

    // clock_t mst_start = clock();
    int *id_vector = union_find_kruskal(elements, element_set_size, graph, graph_size, dimension, groups_amount);
    // clock_t mst_end = clock();

    // clock_t get_groups_start = clock();
    PQueue **groups = generate_groups(elements, element_set_size, id_vector, groups_amount);
    // clock_t get_groups_end = clock();

    // clock_t out_start = clock();
    generate_output(groups, groups_amount, output_file);
    // clock_t out_end = clock();

    // double read_time = ((double)read_end - read_start)/CLOCKS_PER_SEC;
    // double distance_time = ((double)distance_calc_end - distance_calc_start)/CLOCKS_PER_SEC;
    // double sort_time = ((double)sort_edge_end - sort_edge_start)/CLOCKS_PER_SEC;
    // double mst_time = ((double)mst_end - mst_start)/CLOCKS_PER_SEC;
    // double groups_time = ((double)get_groups_end - get_groups_start)/CLOCKS_PER_SEC;
    // double out_time = ((double)out_end - out_start)/CLOCKS_PER_SEC;

    // printf("Tempo de leitura: %lf\n", read_time);
    // printf("Tempo de calculo das distancias: %lf\n", distance_time);
    // printf("Tempo de ordenacao das distancias: %lf\n", sort_time);
    // printf("Tempo de criacao da mst: %lf\n", mst_time);
    // printf("Tempo de identificacao dos grupos: %lf\n", groups_time);
    // printf("Tempo de escrita do arquivo de saida: %lf\n", out_time);

    fclose(file);
    free(id_vector);
    free(input_file);
    free(output_file);
    end_graph(graph, graph_size);
    end_groups(groups, groups_amount);
    end_set(elements, element_set_size);

    return 0;
}
