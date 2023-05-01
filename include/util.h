#ifndef util_h
#define util_h
#include "edge.h"
#include "element.h"
#include "priority_queue.h"

// => Retorna a quantidade de linhas de um arquivo
int get_lines_amount(FILE *file);

// => Retorna a quantidade de dimensões de um vértice presente no arquivo de entrada
short get_dimension(FILE *file);

// => Calcula a distância entre duas coordenadas de N dimensões
double distance(double *e1, double *e2, int dim);

// => Calcula o tamanho do grafo de acoordo com a quantidade de vértices(root)
int calculate_graph_size(int root);

// => Lê os vértices do arquivo de entrada e armazena num vetor
Element **read_elements(FILE *file, int set_size, int dimension);

// => A partir do vetor de vértices gera o grafo (vetor de arestas)
Edge **generate_graph(Element **elements, int graph_size, int set_size, int dimension);

// => Aplica o algoritmo de Kruskal para formar os grupos
int *union_find_kruskal(Element **set, int set_size, Edge **graph, int graph_size, int dimension, int groups_amount);

// => Coleta e organiza os grupos em ordem lexicográfica retornando um vetor de filas de prioridades
PQueue **generate_groups(Element **set, int set_size, int *id_vector, int groups);

// => Libera memória alocada para o vetor de vértices
void end_set(Element **set, int set_size);

// => Libera memória alocada para o vetor de arestas
void end_graph(Edge **graph, int graph_size);

// => Libera memória alocada para a fila de prioridade dos grupos
void end_groups(PQueue **groups, int groups_amount);

// => Gera o arquivo de saída
void generate_output(PQueue **groups, int groups_amount, char *out_file_name);

#endif
