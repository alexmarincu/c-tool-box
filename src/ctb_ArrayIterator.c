#include "ctb_ArrayIterator.h"
#include "ctb.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_ArrayIterator_t * ctb_ArrayIterator_init(
    ctb_ArrayIterator_t * const self,
    ctb_Array_t const * const   array
) {
    ctb_assert(self);
    ctb_assert(array);
    self->array     = array;
    self->nextIndex = 0;
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
bool ctb_ArrayIterator_hasNext(
    ctb_ArrayIterator_t const * const self
) {
    ctb_assert(self);
    return (self->nextIndex < ctb_Array_getCapacity(self->array));
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_ArrayIterator_next(
    ctb_ArrayIterator_t * const self
) {
    ctb_assert(self);
    void * item = NULL;
    if (ctb_ArrayIterator_hasNext(self)) {
        item = ctb_Array_get(self->array, self->nextIndex);
        self->nextIndex++;
    }
    return item;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_ArrayIterator_reset(
    ctb_ArrayIterator_t * const self
) {
    ctb_assert(self);
    self->nextIndex = 0;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_ArrayIterator_forEach(
    ctb_ArrayIterator_t * const                self,
    ctb_ArrayIterator_ForEachOperation_t const operation
) {
    ctb_assert(self);
    ctb_assert(operation);
    void * item;
    while ((item = ctb_ArrayIterator_next(self)) != NULL) {
        operation(item);
    }
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_ArrayIterator_find(
    ctb_ArrayIterator_t * const             self,
    ctb_ArrayIterator_FindPredicate_t const predicate
) {
    ctb_assert(self);
    ctb_assert(predicate);
    bool   itemFound = false;
    void * item;
    while (ctb_ArrayIterator_hasNext(self) && !itemFound) {
        item = ctb_ArrayIterator_next(self);
        if (predicate(item)) {
            itemFound = true;
        }
    }
    if (!itemFound) {
        item = NULL;
    }
    return item;
}
