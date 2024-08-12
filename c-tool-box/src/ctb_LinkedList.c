/*----------------------------------------------------------------------------*/
#include "ctb_LinkedList.h"
/*----------------------------------------------------------------------------*/
#include "ctb.h"
#include "ctb_LinkedListIterator.h"
/*----------------------------------------------------------------------------*/
ctb_LinkedList * ctb_LinkedList_init(ctb_LinkedList * const self) {
    self->_first = NULL;
    self->_last = NULL;
    self->_size = 0;
    return self;
}
/*----------------------------------------------------------------------------*/
void ctb_LinkedList_addByIndex(
    ctb_LinkedList * const self, ctb_Node * const node, size_t const index
) {
    // assert(index <= self->_size);
    if (self->_size == 0) {
        self->_first = node;
        self->_last = node;
    } else {
        if (index == self->_size) {
            ctb_Node * prevNode = self->_last;
            prevNode->next = node;
            node->prev = prevNode;
            self->_last = node;
        } else if (index == 0) {
            ctb_Node * nextNode = self->_first;
            node->next = nextNode;
            nextNode->prev = node;
            self->_first = node;
        } else {
            ctb_Node * nextNode = ctb_LinkedList_getByIndex(self, index);
            nextNode->prev->next = node;
            node->prev = nextNode->prev;
            node->next = nextNode;
            nextNode->prev = node;
        }
    }
    self->_size++;
}
/*----------------------------------------------------------------------------*/
// cppcheck-suppress unusedFunction // API function
void ctb_LinkedList_addFirst(
    ctb_LinkedList * const self, ctb_Node * const node
) {
    ctb_LinkedList_addByIndex(self, node, 0);
}
/*----------------------------------------------------------------------------*/
void ctb_LinkedList_addLast(
    ctb_LinkedList * const self, ctb_Node * const node
) {
    ctb_LinkedList_addByIndex(self, node, self->_size);
}
/*----------------------------------------------------------------------------*/
ctb_Node * ctb_LinkedList_getByIndex(ctb_LinkedList * const self, size_t index) {
    // assert(index < self->_size);
    ctb_Node * node;
    if (index <= self->_size / 2) {
        node = self->_first;
        for (size_t i = 0; i < index; i++) {
            node = node->next;
        }
    } else {
        node = self->_last;
        for (size_t i = self->_size - 1; i > index; i--) {
            node = node->prev;
        }
    }
    return node;
}
/*----------------------------------------------------------------------------*/
// cppcheck-suppress unusedFunction // API function
ctb_Node * ctb_LinkedList_getFirst(ctb_LinkedList * const self) {
    (void)self;
    return self->_first;
}
/*----------------------------------------------------------------------------*/
// cppcheck-suppress unusedFunction // API function
ctb_Node * ctb_LinkedList_getLast(ctb_LinkedList * const self) {
    (void)self;
    return self->_last;
}
/*----------------------------------------------------------------------------*/
ctb_Node * ctb_LinkedList_removeByIndex(
    ctb_LinkedList * const self, size_t const index
) {
    // vsk_Assert_true(vsk_Assert_(), index < self->_size);
    ctb_Node * node;
    if (self->_size == 1) {
        node = self->_first;
        self->_first = NULL;
        self->_last = NULL;
    } else {
        if (index == self->_size - 1) {
            node = self->_last;
            self->_last = node->prev;
            self->_last->next = NULL;
        } else if (index == 0) {
            node = self->_first;
            self->_first = node->next;
            self->_first->prev = NULL;
        } else {
            node = ctb_LinkedList_getByIndex(self, index);
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }
    self->_size--;
    return node;
}
/*----------------------------------------------------------------------------*/
ctb_Node * ctb_LinkedList_removeFirst(ctb_LinkedList * const self) {
    return ctb_LinkedList_removeByIndex(self, 0);
}
/*----------------------------------------------------------------------------*/
ctb_Node * ctb_LinkedList_removeLast(ctb_LinkedList * const self) {
    return ctb_LinkedList_removeByIndex(self, self->_size - 1);
}
/*----------------------------------------------------------------------------*/
// cppcheck-suppress unusedFunction // API function
ctb_Node * ctb_LinkedList_remove(
    ctb_LinkedList * const self, ctb_Node * const node
) {
    // TODO
    (void)self;
    (void)node;
    return NULL;
}
/*----------------------------------------------------------------------------*/
// cppcheck-suppress unusedFunction // API function
size_t ctb_LinkedList_getIndexOf(
    ctb_LinkedList * const self, ctb_Node const * const node
) {
    size_t index = -1;
    bool nodeFound = false;
    ctb_LinkedListIterator * iter =
        ctb_LinkedListIterator_init(&ctb_obj(ctb_LinkedListIterator), self);
    ctb_Node const * _node;
    while ((_node = ctb_LinkedListIterator_next(iter)) && !nodeFound) {
        index++;
        if (node == _node) {
            nodeFound = true;
        }
    }
    if (!nodeFound) {
        index = -1;
    }
    return index;
}
/*----------------------------------------------------------------------------*/
bool ctb_LinkedList_isEmpty(ctb_LinkedList * const self) {
    (void)self;
    return (self->_size == 0);
}
/*----------------------------------------------------------------------------*/
// cppcheck-suppress unusedFunction // API function
size_t ctb_LinkedList_getSize(ctb_LinkedList * const self) {
    (void)self;
    return self->_size;
}
/*----------------------------------------------------------------------------*/
void ctb_LinkedList_clear(ctb_LinkedList * const self) {
    while (self->_size > 0) {
        ctb_LinkedList_removeLast(self);
    }
}
/*----------------------------------------------------------------------------*/
// cppcheck-suppress unusedFunction // API function
void ctb_LinkedList_forEach(
    ctb_LinkedList * const self,
    ctb_LinkedListIteratorForEachOperation const operation
) {
    ctb_LinkedListIterator * iter =
        ctb_LinkedListIterator_init(&ctb_obj(ctb_LinkedListIterator), self);
    ctb_LinkedListIterator_forEach(iter, operation);
}
/*----------------------------------------------------------------------------*/
// cppcheck-suppress unusedFunction // API function
ctb_Node * ctb_LinkedList_find(
    ctb_LinkedList * const self,
    ctb_LinkedListIteratorFindPredicate const predicate
) {
    ctb_LinkedListIterator * iter =
        ctb_LinkedListIterator_init(&ctb_obj(ctb_LinkedListIterator), self);
    return ctb_LinkedListIterator_find(iter, predicate);
}
