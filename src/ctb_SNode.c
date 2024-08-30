#include "ctb_SNode.h"
#include <stddef.h>

// cppcheck-suppress unusedFunction // API function
ctb_SNode_t * ctb_SNode_init(ctb_SNode_t * const self) {
    self->next = NULL;
    return self;
}

// cppcheck-suppress unusedFunction // API function
ctb_SNode_t * ctb_SNode_getNext(ctb_SNode_t * const self) {
    (void)self;
    return self->next;
}
