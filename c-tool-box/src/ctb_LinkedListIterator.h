/*----------------------------------------------------------------------------*/
#ifndef CTB_LINKEDLISTITERATOR_H
#define CTB_LINKEDLISTITERATOR_H
/*----------------------------------------------------------------------------*/
typedef struct ctb_LinkedListIterator ctb_LinkedListIterator;
/*----------------------------------------------------------------------------*/
#include <stdbool.h>
/*----------------------------------------------------------------------------*/
#include "ctb_Node.h"
typedef bool (*ctb_LinkedListIteratorFindPredicate)(ctb_Node * const node);
typedef void (*ctb_LinkedListIteratorForEachOperation)(ctb_Node * const node);
#include "ctb_LinkedList.h"
/*----------------------------------------------------------------------------*/
struct ctb_LinkedListIterator {
    ctb_LinkedList * _linkedList;
    ctb_Node * _current;
};
/*----------------------------------------------------------------------------*/
ctb_LinkedListIterator * ctb_LinkedListIterator_init(
    ctb_LinkedListIterator * const self, ctb_LinkedList * const linkedList
);
bool ctb_LinkedListIterator_hasNext(ctb_LinkedListIterator * const self);
bool ctb_LinkedListIterator_hasPrevious(ctb_LinkedListIterator * const self);
ctb_Node * ctb_LinkedListIterator_next(ctb_LinkedListIterator * const self);
ctb_Node * ctb_LinkedListIterator_previous(ctb_LinkedListIterator * const self);
void ctb_LinkedListIterator_forEach(
    ctb_LinkedListIterator * const self,
    ctb_LinkedListIteratorForEachOperation const operation
);
ctb_Node * ctb_LinkedListIterator_find(
    ctb_LinkedListIterator * const self,
    ctb_LinkedListIteratorFindPredicate const predicate
);
#endif // CTB_LINKEDLISTITERATOR_H
