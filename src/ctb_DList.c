#include "ctb_DList.h"
#include "ctb.h"
#include "ctb_DListIterator.h"
#include <stdint.h>

// cppcheck-suppress unusedFunction // API function
ctb_DList_t * ctb_DList_init(ctb_DList_t * const self) {
    self->first = NULL;
    self->last  = NULL;
    self->size  = 0;
    return self;
}

// cppcheck-suppress unusedFunction // API function
void ctb_DList_addByIndex(
    ctb_DList_t * const self, ctb_DNode_t * const node, size_t const index
) {
    // assert(index <= self->size);
    if (self->size == 0) {
        self->first = node;
        self->last  = node;
    } else {
        if (index == self->size) {
            self->last->next = node;
            node->prev       = self->last;
            self->last       = node;
        } else if (index == 0) {
            node->next        = self->first;
            self->first->prev = node;
            self->first       = node;
        } else {
            ctb_DNode_t * nextNode = ctb_DList_getByIndex(self, index);
            nextNode->prev->next   = node;
            node->prev             = nextNode->prev;
            node->next             = nextNode;
            nextNode->prev         = node;
        }
    }
    self->size++;
}

// cppcheck-suppress unusedFunction // API function
void ctb_DList_addFirst(
    ctb_DList_t * const self, ctb_DNode_t * const node
) {
    ctb_DList_addByIndex(self, node, 0);
}

// cppcheck-suppress unusedFunction // API function
void ctb_DList_addLast(
    ctb_DList_t * const self, ctb_DNode_t * const node
) {
    ctb_DList_addByIndex(self, node, self->size);
}

// cppcheck-suppress unusedFunction // API function
ctb_DNode_t * ctb_DList_getByIndex(ctb_DList_t * const self, size_t index) {
    // assert(index < self->size);
    ctb_DNode_t * node;
    if (index <= self->size / 2) {
        node = self->first;
        for (size_t i = 0; i < index; i++) {
            node = node->next;
        }
    } else {
        node = self->last;
        for (size_t i = self->size - 1; i > index; i--) {
            node = node->prev;
        }
    }
    return node;
}

// cppcheck-suppress unusedFunction // API function
ctb_DNode_t * ctb_DList_getFirst(ctb_DList_t * const self) {
    (void)self;
    return self->first;
}

// cppcheck-suppress unusedFunction // API function
ctb_DNode_t * ctb_DList_getLast(ctb_DList_t * const self) {
    (void)self;
    return self->last;
}

// cppcheck-suppress unusedFunction // API function
ctb_DNode_t * ctb_DList_removeByIndex(
    ctb_DList_t * const self, size_t const index
) {
    // vsk_Assert_true(vsk_Assert_(), index < self->size);
    ctb_DNode_t * node;
    if (self->size == 1) {
        node        = self->first;
        self->first = NULL;
        self->last  = NULL;
    } else {
        if (index == self->size - 1) {
            node             = self->last;
            self->last       = node->prev;
            self->last->next = NULL;
        } else if (index == 0) {
            node              = self->first;
            self->first       = node->next;
            self->first->prev = NULL;
        } else {
            node             = ctb_DList_getByIndex(self, index);
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }
    self->size--;
    return node;
}

// cppcheck-suppress unusedFunction // API function
ctb_DNode_t * ctb_DList_removeFirst(ctb_DList_t * const self) {
    return ctb_DList_removeByIndex(self, 0);
}

// cppcheck-suppress unusedFunction // API function
ctb_DNode_t * ctb_DList_removeLast(ctb_DList_t * const self) {
    return ctb_DList_removeByIndex(self, self->size - 1);
}

// cppcheck-suppress unusedFunction // API function
ctb_DNode_t * ctb_DList_remove(
    ctb_DList_t * const self, ctb_DNode_t * const node
) {
    // TODO
    (void)self;
    (void)node;
    return NULL;
}

// cppcheck-suppress unusedFunction // API function
size_t ctb_DList_getIndexOf(
    ctb_DList_t * const self, ctb_DNode_t const * const node
) {
    size_t                index     = 0;
    bool                  nodeFound = false;
    ctb_DListIterator_t * iter =
        ctb_DListIterator_init(&ctb_obj(ctb_DListIterator_t), self);
    ctb_DNode_t const * _node;
    while ((_node = ctb_DListIterator_next(iter)) && !nodeFound) {
        if (node == _node) {
            nodeFound = true;
        }
        index++;
    }
    if (!nodeFound) {
        index = SIZE_MAX;
    }
    return index;
}

// cppcheck-suppress unusedFunction // API function
bool ctb_DList_isEmpty(ctb_DList_t * const self) {
    (void)self;
    return (self->size == 0);
}

// cppcheck-suppress unusedFunction // API function
size_t ctb_DList_getSize(ctb_DList_t * const self) {
    (void)self;
    return self->size;
}

// cppcheck-suppress unusedFunction // API function
void ctb_DList_clear(ctb_DList_t * const self) {
    while (self->size > 0) {
        ctb_DList_removeLast(self);
    }
}

// cppcheck-suppress unusedFunction // API function
void ctb_DList_forEach(
    ctb_DList_t * const                        self,
    ctb_DListIterator_ForEachOperation_t const operation
) {
    ctb_DListIterator_t * iter =
        ctb_DListIterator_init(&ctb_obj(ctb_DListIterator_t), self);
    ctb_DListIterator_forEach(iter, operation);
}

// cppcheck-suppress unusedFunction // API function
ctb_DNode_t * ctb_DList_find(
    ctb_DList_t * const                     self,
    ctb_DListIterator_FindPredicate_t const predicate
) {
    ctb_DListIterator_t * iter =
        ctb_DListIterator_init(&ctb_obj(ctb_DListIterator_t), self);
    return ctb_DListIterator_find(iter, predicate);
}
