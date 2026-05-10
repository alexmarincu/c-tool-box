#include <string.h>

#include "ctb.h"
#include "ctb_Array.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_Array_t * ctb_Array_init(
    ctb_Array_t * const self
) {
    ctb_assert(self);
    ctb_assert(self->items);
    ctb_assert(self->itemSize > 0);
    ctb_assert(self->capacity > 0);
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_Array_get(
    ctb_Array_t const * const self,
    size_t const              index
) {
    ctb_assert(self);
    if (index >= self->capacity) {
        return NULL;
    }
    return (char *)self->items + (index * self->itemSize);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_Array_set(
    ctb_Array_t * const self,
    size_t const        index,
    void const * const  value
) {
    ctb_assert(self);
    ctb_assert(value);
    if (index >= self->capacity) {
        return;
    }
    void * const dest = (char *)self->items + (index * self->itemSize);
    memcpy(dest, value, self->itemSize);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
size_t ctb_Array_getCapacity(
    ctb_Array_t const * const self
) {
    ctb_assert(self);
    return self->capacity;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
size_t ctb_Array_getItemSize(
    ctb_Array_t const * const self
) {
    ctb_assert(self);
    return self->itemSize;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_Array_forEach(
    ctb_Array_t const * const                  self,
    ctb_ArrayIterator_ForEachOperation_t const operation
) {
    ctb_ArrayIterator_t * iter =
        ctb_ArrayIterator_init(ctb_obj(ctb_ArrayIterator_t), self);
    ctb_ArrayIterator_forEach(iter, operation);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_Array_find(
    ctb_Array_t const * const               self,
    ctb_ArrayIterator_FindPredicate_t const predicate
) {
    ctb_ArrayIterator_t * iter =
        ctb_ArrayIterator_init(ctb_obj(ctb_ArrayIterator_t), self);
    return ctb_ArrayIterator_find(iter, predicate);
}
