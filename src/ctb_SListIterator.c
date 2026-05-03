#include "ctb_SListIterator.h"
#include "ctb.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SListIterator_t * ctb_SListIterator_init(
    ctb_SListIterator_t * const self,
    ctb_SList_t * const         list
) {
    ctb_assert(self);
    ctb_assert(list);
    self->list    = list;
    self->current = ctb_SList_getFirst(list);
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SListIterator_t * ctb_SListIterator_resetToFirst(
    ctb_SListIterator_t * const self
) {
    ctb_assert(self);
    self->current = ctb_SList_getFirst(self->list);
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
bool ctb_SListIterator_hasNext(
    ctb_SListIterator_t const * const self
) {
    ctb_assert(self);
    return (self->current != NULL);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_SListIterator_next(
    ctb_SListIterator_t * const self
) {
    ctb_assert(self);
    ctb_SNode_t * node = NULL;
    if (ctb_SListIterator_hasNext(self)) {
        node          = self->current;
        self->current = ctb_SNode_getNext(self->current);
    }
    return node;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_SListIterator_forEach(
    ctb_SListIterator_t * const                self,
    ctb_SListIterator_ForEachOperation_t const operation
) {
    ctb_assert(self);
    ctb_assert(operation);
    ctb_SNode_t * node;
    while ((node = ctb_SListIterator_next(self))) {
        operation(node);
    }
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_SListIterator_find(
    ctb_SListIterator_t * const             self,
    ctb_SListIterator_FindPredicate_t const predicate
) {
    ctb_assert(self);
    ctb_assert(predicate);
    bool          nodeFound = false;
    ctb_SNode_t * node;
    while (ctb_SListIterator_hasNext(self) && !nodeFound) {
        node = ctb_SListIterator_next(self);
        if (predicate(node)) {
            nodeFound = true;
        }
    }
    if (!nodeFound) {
        node = NULL;
    }
    return node;
}
