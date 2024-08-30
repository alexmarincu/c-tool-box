#include "ctb_DNode.h"
#include <stddef.h>

// cppcheck-suppress unusedFunction // API function
ctb_DNode_t * ctb_DNode_init(ctb_DNode_t * const self) {
    self->next = NULL;
    self->prev = NULL;
    return self;
}

// cppcheck-suppress unusedFunction // API function
ctb_DNode_t * ctb_DNode_getNext(ctb_DNode_t * const self) {
    (void)self;
    return self->next;
}

// cppcheck-suppress unusedFunction // API function
ctb_DNode_t * ctb_DNode_getPrev(ctb_DNode_t * const self) {
    (void)self;
    return self->prev;
}
