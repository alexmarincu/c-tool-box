#include <string.h>

#include "ctb.h"
#include "ctb_DequeArray.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DequeArray_t * ctb_DequeArray_init(
    ctb_DequeArray_t * const self
) {
    ctb_assert(self);
    ctb_assert(self->array.items);
    ctb_assert(self->array.itemSize > 0);
    ctb_assert(self->array.capacity > 0);
    self->head   = 0;
    self->tail   = 0;
    self->length = 0;
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_DequeArray_pushFirst(
    ctb_DequeArray_t * const self,
    void const * const       value
) {
    ctb_assert(self);
    ctb_assert(value);
    if (self->length >= self->array.capacity) {
        return NULL;
    }
    self->head = (self->head == 0)
                     ? self->array.capacity - 1
                     : self->head - 1;
    void * const dest =
        (char *)self->array.items + (self->head * self->array.itemSize);
    memcpy(dest, value, self->array.itemSize);
    self->length++;
    return dest;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_DequeArray_pushLast(
    ctb_DequeArray_t * const self,
    void const * const       value
) {
    ctb_assert(self);
    ctb_assert(value);
    if (self->length >= self->array.capacity) {
        return NULL;
    }
    void * const dest =
        (char *)self->array.items + (self->tail * self->array.itemSize);
    memcpy(dest, value, self->array.itemSize);
    self->tail = (self->tail + 1) % self->array.capacity;
    self->length++;
    return dest;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_DequeArray_popFirst(
    ctb_DequeArray_t * const self
) {
    ctb_assert(self);
    if (self->length == 0) {
        return NULL;
    }
    void * const slot =
        (char *)self->array.items + (self->head * self->array.itemSize);
    self->head = (self->head + 1) % self->array.capacity;
    self->length--;
    return slot;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_DequeArray_popLast(
    ctb_DequeArray_t * const self
) {
    ctb_assert(self);
    if (self->length == 0) {
        return NULL;
    }
    self->tail = (self->tail == 0)
                     ? self->array.capacity - 1
                     : self->tail - 1;
    void * const slot =
        (char *)self->array.items + (self->tail * self->array.itemSize);
    self->length--;
    return slot;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_DequeArray_peekFirst(
    ctb_DequeArray_t const * const self
) {
    ctb_assert(self);
    if (self->length == 0) {
        return NULL;
    }
    return (char *)self->array.items + (self->head * self->array.itemSize);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_DequeArray_peekLast(
    ctb_DequeArray_t const * const self
) {
    ctb_assert(self);
    if (self->length == 0) {
        return NULL;
    }
    size_t const last =
        (self->tail == 0) ? self->array.capacity - 1 : self->tail - 1;
    return (char *)self->array.items + (last * self->array.itemSize);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
bool ctb_DequeArray_isEmpty(
    ctb_DequeArray_t const * const self
) {
    ctb_assert(self);
    return self->length == 0;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
size_t ctb_DequeArray_getLength(
    ctb_DequeArray_t const * const self
) {
    ctb_assert(self);
    return self->length;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
size_t ctb_DequeArray_getCapacity(
    ctb_DequeArray_t const * const self
) {
    ctb_assert(self);
    return self->array.capacity;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_DequeArray_clear(
    ctb_DequeArray_t * const self
) {
    ctb_assert(self);
    self->head   = 0;
    self->tail   = 0;
    self->length = 0;
}
