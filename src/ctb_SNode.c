#include <stddef.h>

#include "ctb_SNode.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_SNode_init(
    ctb_SNode_t * const self
) {
    self->next = NULL;
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_SNode_getNext(
    ctb_SNode_t const * const self
) {
    return self->next;
}
