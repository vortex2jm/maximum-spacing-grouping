#ifndef edge_h
#define edge_h
#include "element.h"

// => Estrutura das arestas
typedef struct edge Edge;

// => instancia uma nova aresta
Edge *init_edge(double distance, Element *e1, Element *e2);

// => Comparador de arestas (compara por tamanho)
int edge_comparator(const void *e1, const void *e2);

// => Retorna o tamanho de uma aresta
double get_edge_distance(Edge *edge);

// => Retorna o primeiro elemento que é conectado pela aresta
Element *get_edge_e1(Edge *edge);

// => Retorna o segundo elemento que é conectado pela aresta
Element *get_edge_e2(Edge *edge);

// => Imprime uma aresta (função auxiliar)
void print_edge(Edge *edge);

// => Libera a memória alocada pela aresta
void end_edge(Edge *edge);

#endif
