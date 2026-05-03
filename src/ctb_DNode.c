#include "ctb_DNode.h"
#include "ctb.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DNode_init(
    ctb_DNode_t * const self
) {
    ctb_assert(self);
    self->next = NULL;
    self->prev = NULL;
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DNode_getNext(
    ctb_DNode_t const * const self
) {
    ctb_assert(self);
    return self->next;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DNode_getPrev(
    ctb_DNode_t const * const self
) {
    ctb_assert(self);
    return self->prev;
}
