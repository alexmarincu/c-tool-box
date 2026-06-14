#include "ctb_StackList.h"

#include "ctb.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_StackList_t * ctb_StackList_init(
    ctb_StackList_t * const self
) {
    ctb_assert(self);
    ctb_SList_init(&self->list);
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_StackList_push(
    ctb_StackList_t * const self,
    ctb_SNode_t * const node
) {
    ctb_assert(self);
    ctb_SList_addFirst(&self->list, node);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_StackList_pop(
    ctb_StackList_t * const self
) {
    ctb_assert(self);
    return ctb_SList_removeFirst(&self->list);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_StackList_peek(
    ctb_StackList_t const * const self
) {
    ctb_assert(self);
    return ctb_SList_getFirst(&self->list);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
bool ctb_StackList_isEmpty(
    ctb_StackList_t const * const self
) {
    ctb_assert(self);
    return ctb_SList_isEmpty(&self->list);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_StackList_clear(
    ctb_StackList_t * const self
) {
    ctb_assert(self);
    ctb_SList_clear(&self->list);
}
