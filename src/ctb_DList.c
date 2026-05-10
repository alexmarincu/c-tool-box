#include <stdint.h>

#include "ctb.h"
#include "ctb_DList.h"
#include "ctb_DListIterator.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DList_t * ctb_DList_init(
    ctb_DList_t * const self
) {
    ctb_assert(self);
    self->first  = NULL;
    self->last   = NULL;
    self->length = 0;
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_DList_addByIndex(
    ctb_DList_t * const self,
    ctb_DNode_t * const node,
    size_t const        index
) {
    ctb_assert(self);
    ctb_assert(node);
    ctb_assert(index <= self->length);
    if (self->length == 0) {
        self->first = node;
        self->last  = node;
    } else {
        if (index == self->length) {
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
    self->length++;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_DList_addFirst(
    ctb_DList_t * const self,
    ctb_DNode_t * const node
) {
    ctb_DList_addByIndex(self, node, 0);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_DList_addLast(
    ctb_DList_t * const self,
    ctb_DNode_t * const node
) {
    ctb_assert(self);
    ctb_DList_addByIndex(self, node, self->length);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DList_getByIndex(
    ctb_DList_t * const self,
    size_t              index
) {
    ctb_assert(self);
    if (!(index < self->length)) {
        return NULL;
    }
    ctb_DNode_t * node;
    if (index <= self->length / 2) {
        node = self->first;
        for (size_t i = 0; i < index; i++) {
            node = node->next;
        }
    } else {
        node = self->last;
        for (size_t i = self->length - 1; i > index; i--) {
            node = node->prev;
        }
    }
    return node;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DList_getFirst(
    ctb_DList_t const * const self
) {
    ctb_assert(self);
    return self->first;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DList_getLast(
    ctb_DList_t const * const self
) {
    ctb_assert(self);
    return self->last;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DList_removeByIndex(
    ctb_DList_t * const self,
    size_t const        index
) {
    ctb_assert(self);
    if (!(index < self->length)) {
        return NULL;
    }
    ctb_DNode_t * node;
    if (self->length == 1) {
        node        = self->first;
        self->first = NULL;
        self->last  = NULL;
    } else if (index == self->length - 1) {
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
    self->length--;
    return node;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DList_removeFirst(
    ctb_DList_t * const self
) {
    return ctb_DList_removeByIndex(self, 0);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DList_removeLast(
    ctb_DList_t * const self
) {
    ctb_assert(self);
    return ctb_DList_removeByIndex(self, self->length - 1);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DList_remove(
    ctb_DList_t * const self,
    ctb_DNode_t * const node
) {
    ctb_assert(self);
    ctb_assert(node);
    ctb_DNode_t * removedNode = NULL;
    if (self->first == node) {
        removedNode = ctb_DList_removeFirst(self);
    } else if (self->last == node) {
        removedNode = ctb_DList_removeLast(self);
    } else {
        ctb_DNode_t const * curr = self->first;
        while (curr != NULL && curr->next != node) {
            curr = curr->next;
        }
        if (curr != NULL) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            self->length--;
            removedNode = node;
        }
    }
    return removedNode;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
size_t ctb_DList_getIndexOf(
    ctb_DList_t * const       self,
    ctb_DNode_t const * const node
) {
    ctb_assert(self);
    ctb_assert(node);
    size_t                index     = 0;
    bool                  nodeFound = false;
    ctb_DListIterator_t * iter =
        ctb_DListIterator_init(ctb_obj(ctb_DListIterator_t), self);
    ctb_DNode_t const * currentNode;
    while (!nodeFound && (currentNode = ctb_DListIterator_next(iter))) {
        if (node == currentNode) {
            nodeFound = true;
        } else {
            index++;
        }
    }
    if (!nodeFound) {
        index = SIZE_MAX;
    }
    return index;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
bool ctb_DList_isEmpty(
    ctb_DList_t const * const self
) {
    ctb_assert(self);
    return (self->length == 0);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
size_t ctb_DList_getLength(
    ctb_DList_t const * const self
) {
    ctb_assert(self);
    return self->length;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_DList_clear(
    ctb_DList_t * const self
) {
    ctb_assert(self);
    while (ctb_DList_removeLast(self)) { ; }
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_DList_forEach(
    ctb_DList_t * const                        self,
    ctb_DListIterator_ForEachOperation_t const operation
) {
    ctb_DListIterator_t * iter =
        ctb_DListIterator_init(ctb_obj(ctb_DListIterator_t), self);
    ctb_DListIterator_forEach(iter, operation);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_DNode_t * ctb_DList_find(
    ctb_DList_t * const                     self,
    ctb_DListIterator_FindPredicate_t const predicate
) {
    ctb_DListIterator_t * iter =
        ctb_DListIterator_init(ctb_obj(ctb_DListIterator_t), self);
    return ctb_DListIterator_find(iter, predicate);
}
