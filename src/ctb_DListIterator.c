#include "ctb_DListIterator.h"

// cppcheck-suppress unusedFunction // API function
ctb_DListIterator_t * ctb_DListIterator_init(
    ctb_DListIterator_t * const self, ctb_DList_t * const list
) {
    self->list    = list;
    self->current = ctb_DList_getFirst(list);
    return self;
}

// cppcheck-suppress unusedFunction // API function
ctb_DListIterator_t * ctb_DListIterator_resetToFirst(
    ctb_DListIterator_t * const self
) {
    self->current = ctb_DList_getFirst(self->list);
    return self;
}

// cppcheck-suppress unusedFunction // API function
ctb_DListIterator_t * ctb_DListIterator_resetToLast(
    ctb_DListIterator_t * const self
) {
    self->current = ctb_DList_getLast(self->list);
    return self;
}

// cppcheck-suppress unusedFunction // API function
bool ctb_DListIterator_hasNext(ctb_DListIterator_t * const self) {
    (void)self;
    return (self->current != NULL);
}

// cppcheck-suppress unusedFunction // API function
bool ctb_DListIterator_hasPrevious(ctb_DListIterator_t * const self) {
    (void)self;
    return (self->current != NULL);
}

// cppcheck-suppress unusedFunction // API function
ctb_DNode_t * ctb_DListIterator_next(ctb_DListIterator_t * const self) {
    ctb_DNode_t * node = NULL;
    if (ctb_DListIterator_hasNext(self)) {
        node          = self->current;
        self->current = ctb_DNode_getNext(self->current);
    }
    return node;
}

// cppcheck-suppress unusedFunction // API function
ctb_DNode_t * ctb_DListIterator_previous(ctb_DListIterator_t * const self) {
    ctb_DNode_t * node = NULL;
    if (ctb_DListIterator_hasPrevious(self)) {
        node          = self->current;
        self->current = ctb_DNode_getPrev(self->current);
    }
    return node;
}

// cppcheck-suppress unusedFunction // API function
void ctb_DListIterator_forEach(
    ctb_DListIterator_t * const                self,
    ctb_DListIterator_ForEachOperation_t const operation
) {
    ctb_DNode_t * node;
    while ((node = ctb_DListIterator_next(self))) {
        operation(node);
    }
}

// cppcheck-suppress unusedFunction // API function
ctb_DNode_t * ctb_DListIterator_find(
    ctb_DListIterator_t * const             self,
    ctb_DListIterator_FindPredicate_t const predicate
) {
    bool          nodeFound = false;
    ctb_DNode_t * node;
    while (ctb_DListIterator_hasNext(self) && !nodeFound) {
        node = ctb_DListIterator_next(self);
        if (predicate(node)) {
            nodeFound = true;
        }
    }
    if (!nodeFound) {
        node = NULL;
    }
    return node;
}
