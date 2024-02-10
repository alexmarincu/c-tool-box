/*----------------------------------------------------------------------------*/
#ifndef CTB_LINKEDLIST_H
#define CTB_LINKEDLIST_H
/*----------------------------------------------------------------------------*/
typedef struct ctb_LinkedList ctb_LinkedList;
/*----------------------------------------------------------------------------*/
#include <stdbool.h>
#include <stddef.h>
/*----------------------------------------------------------------------------*/
#include "ctb_LinkedListIterator.h"
#include "ctb_Node.h"
/*----------------------------------------------------------------------------*/
struct ctb_LinkedList {
    ctb_Node * _first;
    ctb_Node * _last;
    size_t _size;
};
/*----------------------------------------------------------------------------*/
ctb_LinkedList * ctb_LinkedList_init(ctb_LinkedList * const self);
void ctb_LinkedList_addByIndex(
    ctb_LinkedList * const self, ctb_Node * const node, size_t const index
);
void ctb_LinkedList_addFirst(
    ctb_LinkedList * const self, ctb_Node * const node
);
void ctb_LinkedList_addLast(ctb_LinkedList * const self, ctb_Node * const node);
ctb_Node * ctb_LinkedList_getByIndex(ctb_LinkedList * const self, size_t index);
ctb_Node * ctb_LinkedList_getFirst(ctb_LinkedList * const self);
ctb_Node * ctb_LinkedList_getLast(ctb_LinkedList * const self);
ctb_Node * ctb_LinkedList_removeByIndex(
    ctb_LinkedList * const self, size_t const index
);
ctb_Node * ctb_LinkedList_removeFirst(ctb_LinkedList * const self);
ctb_Node * ctb_LinkedList_removeLast(ctb_LinkedList * const self);
ctb_Node * ctb_LinkedList_remove(
    ctb_LinkedList * const self, ctb_Node * const node
);
size_t ctb_LinkedList_getIndexOf(
    ctb_LinkedList * const self, ctb_Node * const node
);
bool ctb_LinkedList_isEmpty(ctb_LinkedList * const self);
size_t ctb_LinkedList_getSize(ctb_LinkedList * const self);
void ctb_LinkedList_clear(ctb_LinkedList * const self);
void ctb_LinkedList_forEach(
    ctb_LinkedList * const self,
    ctb_LinkedListIteratorForEachOperation const operation
);
ctb_Node * ctb_LinkedList_find(
    ctb_LinkedList * const self,
    ctb_LinkedListIteratorFindPredicate const predicate
);
#endif // CTB_LINKEDLIST_H
