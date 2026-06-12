#include <string.h>

#include "ctb.h"
#include "ctb_QueueArray.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_QueueArray_t * ctb_QueueArray_init(
    ctb_QueueArray_t * const self
) {
    ctb_assert(self);
    ctb_assert(self->array.items);
    ctb_assert(self->array.itemSize > 0);
    ctb_assert(self->array.capacity > 0);
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
bool ctb_QueueArray_isEmpty(
    ctb_QueueArray_t const * const self
) {
    ctb_assert(self);
    return self->length == 0;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
size_t ctb_QueueArray_getLength(
    ctb_QueueArray_t const * const self
) {
    ctb_assert(self);
    return self->length;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
size_t ctb_QueueArray_getCapacity(
    ctb_QueueArray_t const * const self
) {
    ctb_assert(self);
    return self->array.capacity;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_QueueArray_enqueue(
    ctb_QueueArray_t * const self,
    void const * const       value
) {
    ctb_assert(self);
    ctb_assert(value);
    if (self->length >= self->array.capacity) {
        return;
    }
    void * const dest = (char *)self->array.items + (self->tail * self->array.itemSize);
    memcpy(dest, value, self->array.itemSize);
    self->tail = (self->tail + 1) % self->array.capacity;
    self->length++;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_QueueArray_dequeue(
    ctb_QueueArray_t * const self
) {
    ctb_assert(self);
    if (self->length == 0) {
        return NULL;
    }
    void * const item = (char *)self->array.items + (self->head * self->array.itemSize);
    self->head = (self->head + 1) % self->array.capacity;
    self->length--;
    return item;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void * ctb_QueueArray_peek(
    ctb_QueueArray_t const * const self
) {
    ctb_assert(self);
    if (self->length == 0) {
        return NULL;
    }
    return (char *)self->array.items + (self->head * self->array.itemSize);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_QueueArray_clear(
    ctb_QueueArray_t * const self
) {
    ctb_assert(self);
    self->head   = 0;
    self->tail   = 0;
    self->length = 0;
}
