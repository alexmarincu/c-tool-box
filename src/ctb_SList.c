#include <stdint.h>

#include "ctb.h"
#include "ctb_SList.h"
#include "ctb_SListIterator.h"

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SList_t * ctb_SList_init(
    ctb_SList_t * const self
) {
    self->first = NULL;
    self->size  = 0;
    return self;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
bool ctb_SList_isEmpty(
    ctb_SList_t const * const self
) {
    return (self->size == 0);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
size_t ctb_SList_getSize(
    ctb_SList_t const * const self
) {
    return self->size;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_SList_addByIndex(
    ctb_SList_t * const self,
    ctb_SNode_t * const node,
    size_t const        index
) {
    if (index == 0) {
        node->next  = self->first;
        self->first = node;
    } else {
        ctb_SNode_t * const prevNode = ctb_SList_getByIndex(self, index - 1);
        node->next                   = prevNode->next;
        prevNode->next               = node;
    }
    self->size++;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_SList_addFirst(
    ctb_SList_t * const self,
    ctb_SNode_t * const node
) {
    ctb_SList_addByIndex(self, node, 0);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_SList_addLast(
    ctb_SList_t * const self,
    ctb_SNode_t * const node
) {
    ctb_SList_addByIndex(self, node, self->size);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_SList_getByIndex(
    ctb_SList_t * const self,
    size_t const        index
) {
    ctb_SNode_t * node = self->first;
    for (size_t i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_SList_getFirst(
    ctb_SList_t const * const self
) {
    return self->first;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_SList_getLast(
    ctb_SList_t const * const self
) {
    ctb_SNode_t * node = self->first;
    if (node != NULL) {
        while (node->next != NULL) {
            node = node->next;
        }
    }
    return node;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_SList_removeByIndex(
    ctb_SList_t * const self,
    size_t const        index
) {
    ctb_SNode_t * node;
    if (index == 0) {
        node        = self->first;
        self->first = node->next;
    } else {
        ctb_SNode_t * const prevNode = ctb_SList_getByIndex(self, index - 1);
        node                         = prevNode->next;
        prevNode->next               = node->next;
    }
    self->size--;
    return node;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_SList_removeFirst(
    ctb_SList_t * const self
) {
    return ctb_SList_removeByIndex(self, 0);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_SList_removeLast(
    ctb_SList_t * const self
) {
    return ctb_SList_removeByIndex(self, self->size - 1);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_SList_remove(
    ctb_SList_t * const       self,
    ctb_SNode_t const * const node
) {
    ctb_SNode_t * removedNode = NULL;
    if (self->first == node) {
        removedNode = ctb_SList_removeFirst(self);
    } else {
        ctb_SNode_t * curr = self->first;
        while (curr != NULL && curr->next != node) {
            curr = curr->next;
        }
        if (curr != NULL) {
            removedNode = curr->next;
            curr->next  = removedNode->next;
            self->size--;
        }
    }
    return removedNode;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
size_t ctb_SList_getIndexOf(
    ctb_SList_t const * const self,
    ctb_SNode_t const * const node
) {
    size_t              index     = 0;
    bool                nodeFound = false;
    ctb_SNode_t const * curr      = self->first;
    while (curr != NULL && !nodeFound) {
        if (curr == node) {
            nodeFound = true;
        } else {
            index++;
            curr = curr->next;
        }
    }
    if (!nodeFound) {
        index = SIZE_MAX;
    }
    return index;
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_SList_clear(
    ctb_SList_t * const self
) {
    while (self->size > 0) {
        ctb_SList_removeFirst(self);
    }
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
void ctb_SList_forEach(
    ctb_SList_t * const                        self,
    ctb_SListIterator_ForEachOperation_t const operation
) {
    ctb_SListIterator_t * iter =
        ctb_SListIterator_init(&ctb_obj(ctb_SListIterator_t), self);
    ctb_SListIterator_forEach(iter, operation);
}

// cppcheck-suppress [staticFunction, unusedFunction] - API function
ctb_SNode_t * ctb_SList_find(
    ctb_SList_t * const                     self,
    ctb_SListIterator_FindPredicate_t const predicate
) {
    ctb_SListIterator_t * iter =
        ctb_SListIterator_init(&ctb_obj(ctb_SListIterator_t), self);
    return ctb_SListIterator_find(iter, predicate);
}
