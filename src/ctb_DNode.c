#include <stddef.h>

#include "ctb_DNode.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DNode_init(
    ctb_DNode_t * const self
) {
    self->next = NULL;
    self->prev = NULL;
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DNode_getNext(
    ctb_DNode_t const * const self
) {
    return self->next;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DNode_getPrev(
    ctb_DNode_t const * const self
) {
    return self->prev;
}
