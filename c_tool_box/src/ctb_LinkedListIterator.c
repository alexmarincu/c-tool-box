/*----------------------------------------------------------------------------*/
#include "ctb_LinkedListIterator.h"
/*----------------------------------------------------------------------------*/
ctb_LinkedListIterator * ctb_LinkedListIterator_init(
    ctb_LinkedListIterator * const self, ctb_LinkedList * const linkedList
) {
    self->_linkedList = linkedList;
    self->_current = linkedList->_first;
    return self;
}
/*----------------------------------------------------------------------------*/
bool ctb_LinkedListIterator_hasNext(ctb_LinkedListIterator * const self) {
    return (self->_current != NULL);
}
/*----------------------------------------------------------------------------*/
bool ctb_LinkedListIterator_hasPrevious(ctb_LinkedListIterator * const self) {
    // TODO
    return false;
}
/*----------------------------------------------------------------------------*/
ctb_Node * ctb_LinkedListIterator_next(ctb_LinkedListIterator * const self) {
    ctb_Node * node = NULL;
    if (ctb_LinkedListIterator_hasNext(self)) {
        node = self->_current;
        self->_current = self->_current->next;
    }
    return node;
}
/*----------------------------------------------------------------------------*/
ctb_Node * ctb_LinkedListIterator_previous(ctb_LinkedListIterator * const self) {
    // TODO
    return NULL;
}
/*----------------------------------------------------------------------------*/
void ctb_LinkedListIterator_forEach(
    ctb_LinkedListIterator * const self,
    ctb_LinkedListIteratorForEachOperation const operation
) {
    ctb_Node * node;
    while ((node = ctb_LinkedListIterator_next(self))) {
        operation(node);
    }
}
/*----------------------------------------------------------------------------*/
ctb_Node * ctb_LinkedListIterator_find(
    ctb_LinkedListIterator * const self,
    ctb_LinkedListIteratorFindPredicate const predicate
) {
    bool nodeFound = false;
    void * node;
    while (ctb_LinkedListIterator_hasNext(self) && !nodeFound) {
        node = ctb_LinkedListIterator_next(self);
        if (predicate(node)) {
            nodeFound = true;
        }
    }
    if (!nodeFound) {
        node = NULL;
    }
    return node;
}
