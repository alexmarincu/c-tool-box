#include <string.h>

#include "ctb.h"
#include "ctb_StackArray.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_StackArray_t * ctb_StackArray_init(
    ctb_StackArray_t * const self
) {
    ctb_assert(self);
    ctb_assert(self->array.items);
    ctb_assert(self->array.itemSize > 0);
    ctb_assert(self->array.capacity > 0);
    self->length = 0;
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_StackArray_push(
    ctb_StackArray_t * const self,
    void const * const       value
) {
    ctb_assert(self);
    ctb_assert(value);
    if (self->length >= self->array.capacity) {
        return NULL;
    }
    void * const dest =
        (char *)self->array.items + (self->length * self->array.itemSize);
    memcpy(dest, value, self->array.itemSize);
    self->length++;
    return dest;
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
    return (char *)self->array.items + (self->length * self->array.itemSize);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_StackArray_peek(
    ctb_StackArray_t const * const self
) {
    ctb_assert(self);
    if (self->length == 0) {
        return NULL;
    }
    return (char *)self->array.items +
           ((self->length - 1) * self->array.itemSize);
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
void ctb_StackArray_clear(
    ctb_StackArray_t * const self
) {
    ctb_assert(self);
    self->length = 0;
}
