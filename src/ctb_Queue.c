#include "ctb_Queue.h"

// cppcheck-suppress unusedFunction // API function
ctb_Queue_t * ctb_Queue_init(ctb_Queue_t * const self) {
    ctb_DList_init(&self->list);
    return self;
}

// cppcheck-suppress unusedFunction // API function
bool ctb_Queue_isEmpty(ctb_Queue_t * const self) {
    return ctb_DList_isEmpty(&self->list);
}

// cppcheck-suppress unusedFunction // API function
void ctb_Queue_enqueue(
    ctb_Queue_t * const self, ctb_DNode_t * const node
) {
    ctb_DList_addLast(&self->list, node);
}

// cppcheck-suppress unusedFunction // API function
ctb_DNode_t * ctb_Queue_dequeue(ctb_Queue_t * const self) {
    return ctb_DList_removeFirst(&self->list);
}

// cppcheck-suppress unusedFunction // API function
void ctb_Queue_clear(ctb_Queue_t * const self) {
    ctb_DList_clear(&self->list);
}
