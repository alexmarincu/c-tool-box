#include "ctb_StackArray.h"

#include "ctb.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_StackArray_t * ctb_StackArray_init(
    ctb_StackArray_t * const self
) {
    ctb_assert(self);
    ctb_Array_init(&self->array);
    self->length = 0;
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
bool ctb_StackArray_isEmpty(
    ctb_StackArray_t const * const self
) {
    ctb_assert(self);
    return self->length == 0;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
size_t ctb_StackArray_getLength(
    ctb_StackArray_t const * const self
) {
    ctb_assert(self);
    return self->length;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
size_t ctb_StackArray_getCapacity(
    ctb_StackArray_t const * const self
) {
    ctb_assert(self);
    return ctb_Array_getCapacity(&self->array);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_StackArray_push(
    ctb_StackArray_t * const self,
    void const * const       value
) {
    ctb_assert(self);
    ctb_assert(value);
    ctb_assert(self->length < ctb_Array_getCapacity(&self->array));
    ctb_Array_set(&self->array, self->length, value);
    self->length++;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_StackArray_pop(
    ctb_StackArray_t * const self
) {
    ctb_assert(self);
    if (self->length == 0) {
        return NULL;
    }
    self->length--;
    return ctb_Array_get(&self->array, self->length);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_StackArray_peek(
    ctb_StackArray_t const * const self
) {
    ctb_assert(self);
    if (self->length == 0) {
        return NULL;
    }
    return ctb_Array_get(&self->array, self->length - 1);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_StackArray_clear(
    ctb_StackArray_t * const self
) {
    ctb_assert(self);
    self->length = 0;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_StackArray_forEach(
    ctb_StackArray_t const * const                  self,
    ctb_ArrayIterator_ForEachOperation_t const operation
) {
    ctb_assert(self);
    ctb_ArrayIterator_t * iter =
        ctb_ArrayIterator_init(ctb_obj(ctb_ArrayIterator_t), &self->array);
    ctb_ArrayIterator_forEach(iter, operation);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_StackArray_find(
    ctb_StackArray_t const * const               self,
    ctb_ArrayIterator_FindPredicate_t const predicate
) {
    ctb_assert(self);
    ctb_ArrayIterator_t * iter =
        ctb_ArrayIterator_init(ctb_obj(ctb_ArrayIterator_t), &self->array);
    return ctb_ArrayIterator_find(iter, predicate);
}
