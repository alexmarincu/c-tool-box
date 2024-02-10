/*----------------------------------------------------------------------------*/
#ifndef CTB_LINKEDQUEUE_H
#define CTB_LINKEDQUEUE_H
/*----------------------------------------------------------------------------*/
typedef struct ctb_LinkedQueue ctb_LinkedQueue;
/*----------------------------------------------------------------------------*/
#include <stdbool.h>
/*----------------------------------------------------------------------------*/
#include "ctb_LinkedList.h"
/*----------------------------------------------------------------------------*/
struct ctb_LinkedQueue {
    ctb_LinkedList _linkedList;
};
/*----------------------------------------------------------------------------*/
ctb_LinkedQueue * ctb_LinkedQueue_init(ctb_LinkedQueue * const self);
bool ctb_LinkedQueue_isEmpty(ctb_LinkedQueue * const self);
void ctb_LinkedQueue_enqueue(
    ctb_LinkedQueue * const self, ctb_Node * const node
);
ctb_Node * ctb_LinkedQueue_dequeue(ctb_LinkedQueue * const self);
void ctb_LinkedQueue_clear(ctb_LinkedQueue * const self);
#endif // CTB_LINKEDQUEUE_H
