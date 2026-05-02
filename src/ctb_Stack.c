#include "ctb_Stack.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_Stack_t * ctb_Stack_init(
    ctb_Stack_t * const self
) {
    ctb_SList_init(&self->list);

    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_Stack_push(
    ctb_Stack_t * const self,
    ctb_SNode_t * const node
) {
    ctb_SList_addFirst(&self->list, node);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_Stack_pop(
    ctb_Stack_t * const self
) {
    ctb_SNode_t * node = NULL;

    if (!ctb_Stack_isEmpty(self)) {
        node = ctb_SList_removeFirst(&self->list);
    }

    return node;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_Stack_peek(
    ctb_Stack_t const * const self
) {
    return ctb_SList_getFirst(&self->list);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
bool ctb_Stack_isEmpty(
    ctb_Stack_t const * const self
) {
    return ctb_SList_isEmpty(&self->list);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_Stack_clear(
    ctb_Stack_t * const self
) {
    ctb_SList_clear(&self->list);
}
