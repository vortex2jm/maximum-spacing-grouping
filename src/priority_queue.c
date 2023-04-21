#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/priority_queue.h"

typedef struct cell Cell;

struct cell
{
  Element *element;
  Cell *next;
};

struct p_queue
{
  Cell *first;
  Cell *last;
};

PQueue *init_queue()
{
  PQueue *q = malloc(sizeof(PQueue));
  q->first = NULL;
  q->last = NULL;
  return q;
}

void end_queue(PQueue * queue){
  if(queue){
    Cell * current = queue->first, *aux;
    while(current){
      aux = current->next;
      free(current);
      current = aux;
    }
    free(queue);
  }
}

PQueue *q_push(PQueue *queue, Element *element)
{
  Cell *current = queue->first, *previous = NULL;
  Cell *newCell = malloc(sizeof(Cell));
  newCell->element = element;
  newCell->next = NULL;

  // se a queuea estiver vazia, insere na primeira posição(que também será a últ
  // ma)
  if (!queue->first)
  {
    queue->first = newCell;
    queue->last = newCell;
    return queue;
  }
  // Caso contrário percorre a queuea e insere na posição ordenada
  while (current)
  {
    if (strcmp(get_element_name(element), get_element_name(current->element)) < 0)
    {
      if (current == queue->first)
      {
        newCell->next = current;
        queue->first = newCell;
      }
      else
      {
        previous->next = newCell;
        newCell->next = current;
      }
      break;
    }
    if (current == queue->last)
    {
      current->next = newCell;
      queue->last = newCell;
      break;
    }
    previous = current;
    current = current->next;
  }
  return queue;
}

Element *get_first_queue_element(PQueue *queue)
{
  return queue->first->element;
}

void print_queue(PQueue *queue, FILE * file)
{
  Cell *current = queue->first;
  while (current)
  {
    print_element(current->element, file);

    if (current->next)
      fprintf(file, ",");
    current = current->next;
  }
  fprintf(file, "\n");
}

int queue_comparator(const void *q1, const void *q2)
{
  PQueue *(*a) = (PQueue **)q1;
  PQueue *(*b) = (PQueue **)q2;

  char *n1 = get_element_name(get_first_queue_element(*a));
  char *n2 = get_element_name(get_first_queue_element(*b));

  if (strcmp(n1, n2) < 0)
  {
    return -1;
  }
  if (strcmp(n1, n2) > 0)
  {
    return 1;
  }
  return 0;
}
