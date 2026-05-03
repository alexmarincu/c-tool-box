#include "ctb_DListIterator.h"
#include "ctb.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DListIterator_t * ctb_DListIterator_init(
    ctb_DListIterator_t * const self,
    ctb_DList_t * const         list
) {
    ctb_assert(self);
    ctb_assert(list);
    self->list    = list;
    self->current = ctb_DList_getFirst(list);
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DListIterator_t * ctb_DListIterator_resetToFirst(
    ctb_DListIterator_t * const self
) {
    ctb_assert(self);
    self->current = ctb_DList_getFirst(self->list);
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DListIterator_t * ctb_DListIterator_resetToLast(
    ctb_DListIterator_t * const self
) {
    ctb_assert(self);
    self->current = ctb_DList_getLast(self->list);
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
bool ctb_DListIterator_hasNext(
    ctb_DListIterator_t const * const self
) {
    ctb_assert(self);
    return (self->current != NULL);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
bool ctb_DListIterator_hasPrevious(
    ctb_DListIterator_t const * const self
) {
    ctb_assert(self);
    return (self->current != NULL);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DListIterator_next(
    ctb_DListIterator_t * const self
) {
    ctb_assert(self);
    ctb_DNode_t * node = NULL;
    if (ctb_DListIterator_hasNext(self)) {
        node          = self->current;
        self->current = ctb_DNode_getNext(self->current);
    }
    return node;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DListIterator_previous(
    ctb_DListIterator_t * const self
) {
    ctb_assert(self);
    ctb_DNode_t * node = NULL;
    if (ctb_DListIterator_hasPrevious(self)) {
        node          = self->current;
        self->current = ctb_DNode_getPrev(self->current);
    }
    return node;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_DListIterator_forEach(
    ctb_DListIterator_t * const                self,
    ctb_DListIterator_ForEachOperation_t const operation
) {
    ctb_assert(self);
    ctb_assert(operation);
    ctb_DNode_t * node;
    while ((node = ctb_DListIterator_next(self))) {
        operation(node);
    }
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DListIterator_find(
    ctb_DListIterator_t * const             self,
    ctb_DListIterator_FindPredicate_t const predicate
) {
    ctb_assert(self);
    ctb_assert(predicate);
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
