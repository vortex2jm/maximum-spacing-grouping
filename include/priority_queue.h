#ifndef priority_queue_h
#define priority_queue_h
#include "element.h"

typedef struct p_queue PQueue;

PQueue *init_queue();

PQueue *q_push(PQueue *queue, Element *element);

void print_queue(PQueue *queue);

int queue_comparator(const void *q1, const void *q2);

#endif
