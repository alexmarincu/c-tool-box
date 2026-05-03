#include "ctb_SNode.h"

#include "ctb.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_SNode_init(
    ctb_SNode_t * const self
) {
    ctb_assert(self);
    self->next = NULL;
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_SNode_getNext(
    ctb_SNode_t const * const self
) {
    ctb_assert(self);
    return self->next;
}
