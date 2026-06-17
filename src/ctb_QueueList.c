#include "ctb_QueueList.h"
#include "ctb.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_QueueList_t * ctb_QueueList_init(
    ctb_QueueList_t * const self
) {
    ctb_assert(self);
    ctb_DList_init(&self->list);
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
bool ctb_QueueList_isEmpty(
    ctb_QueueList_t * const self
) {
    ctb_assert(self);
    return ctb_DList_isEmpty(&self->list);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_QueueList_enqueue(
    ctb_QueueList_t * const self,
    ctb_DNode_t * const node
) {
    ctb_assert(self);
    ctb_DList_addLast(&self->list, node);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_QueueList_dequeue(
    ctb_QueueList_t * const self
) {
    ctb_assert(self);
    return ctb_DList_removeFirst(&self->list);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_QueueList_clear(
    ctb_QueueList_t * const self
) {
    ctb_assert(self);
    ctb_DList_clear(&self->list);
}
