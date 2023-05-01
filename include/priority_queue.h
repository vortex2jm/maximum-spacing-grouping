#ifndef priority_queue_h
#define priority_queue_h
#include "element.h"

// => Estrutura da fila de prioridade (ordem lexicográfica)
typedef struct p_queue PQueue;

// => Instancia uma nova fila
PQueue *init_queue();

// => Insere um vértice na fila
PQueue *q_push(PQueue *queue, Element *element);

// => Imprime a fila de vértices no arquivo de saída
void print_queue(PQueue *queue, FILE *file);

// => Comparador de filas (compara em ordem lexicográfica)
int queue_comparator(const void *q1, const void *q2);

// => Libera a memória alocada para uma fila
void end_queue(PQueue *queue);

#endif
