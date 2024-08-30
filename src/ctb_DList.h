/**
 * @file
 */
#ifndef CTB_DLIST_H
#define CTB_DLIST_H

/**
 * @brief Doubly linked list type
 */
typedef struct ctb_DList ctb_DList_t;

#include "ctb_DListIterator.h"
#include "ctb_DNode.h"
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Doubly linked list data structure
 */
struct ctb_DList {
    ctb_DNode_t * first; /**< Pointer to the first node */
    ctb_DNode_t * last;  /**< Pointer to the last node */
    size_t        size;  /**< Number of nodes */
};

/**
 * @brief Initializes a doubly linked list
 *
 * @param self Pointer to a doubly linked list
 * @return Pointer to the initialized doubly linked list
 */
ctb_DList_t * ctb_DList_init(ctb_DList_t * const self);

/**
 * @brief Adds a node at the specified index
 *
 * @param self Pointer to a doubly linked list
 * @param node Pointer to the node to add
 * @param index Index where to add the node
 */
void ctb_DList_addByIndex(
    ctb_DList_t * const self, ctb_DNode_t * const node, size_t const index
);

/**
 * @brief Adds a node at the beginning
 *
 * @param self Pointer to a doubly linked list
 * @param node Pointer to the node to add
 */
void ctb_DList_addFirst(
    ctb_DList_t * const self, ctb_DNode_t * const node
);

/**
 * @brief Adds a node at the end
 *
 * @param self Pointer to a doubly linked list
 * @param node Pointer to the node to add
 */
void ctb_DList_addLast(ctb_DList_t * const self, ctb_DNode_t * const node);

/**
 * @brief Returns the node at the specified index
 *
 * @param self Pointer to a doubly linked list
 * @param index Index of the node to return
 * @return Pointer to the node at the specified index
 */
ctb_DNode_t * ctb_DList_getByIndex(ctb_DList_t * const self, size_t index);

/**
 * @brief Returns the first node
 *
 * @param self Pointer to a doubly linked list
 * @return Pointer to the first node
 */
ctb_DNode_t * ctb_DList_getFirst(ctb_DList_t * const self);

/**
 * @brief Returns the last node
 *
 * @param self Pointer to a doubly linked list
 * @return Pointer to the last node
 */
ctb_DNode_t * ctb_DList_getLast(ctb_DList_t * const self);

/**
 * @brief Removes the node at the specified index
 *
 * @param self Pointer to a doubly linked list
 * @param index Index of the node to remove
 * @return Pointer to the removed node
 */
ctb_DNode_t * ctb_DList_removeByIndex(
    ctb_DList_t * const self, size_t const index
);

/**
 * @brief Removes the first node
 *
 * @param self Pointer to a doubly linked list
 * @return Pointer to the removed node
 */
ctb_DNode_t * ctb_DList_removeFirst(ctb_DList_t * const self);

/**
 * @brief Removes the last node
 *
 * @param self Pointer to a doubly linked list
 * @return Pointer to the removed node
 */
ctb_DNode_t * ctb_DList_removeLast(ctb_DList_t * const self);

/**
 * @brief Removes a node
 *
 * @param self Pointer to a doubly linked list
 * @param node Pointer to the node to remove
 * @return Pointer to the removed node
 */
ctb_DNode_t * ctb_DList_remove(
    ctb_DList_t * const self, ctb_DNode_t * const node
);

/**
 * @brief Returns the index of a node
 *
 * @param self Pointer to a doubly linked list
 * @param node Pointer to the node
 * @return Index of the node, or SIZE_MAX if the node is not found
 */
size_t ctb_DList_getIndexOf(
    ctb_DList_t * const self, ctb_DNode_t const * const node
);

/**
 * @brief Checks if the doubly linked list is empty
 *
 * @param self Pointer to a doubly linked list
 * @return True if the doubly linked list is empty, false otherwise
 */
bool ctb_DList_isEmpty(ctb_DList_t * const self);

/**
 * @brief Returns the size of the doubly linked list
 *
 * @param self Pointer to a doubly linked list
 * @return Size of the doubly linked list
 */
size_t ctb_DList_getSize(ctb_DList_t * const self);

/**
 * @brief Clears the doubly linked list
 *
 * @param self Pointer to a doubly linked list
 */
void ctb_DList_clear(ctb_DList_t * const self);

/**
 * @brief Applies an operation to each node of the doubly linked list
 *
 * @param self Pointer to a doubly linked list
 * @param operation Operation to apply to each node
 */
void ctb_DList_forEach(
    ctb_DList_t * const                        self,
    ctb_DListIterator_ForEachOperation_t const operation
);

/**
 * @brief Finds a node in the doubly linked list that matches a predicate
 *
 * @param self Pointer to a doubly linked list
 * @param predicate Predicate to match a node
 * @return Pointer to the first node that matches the predicate, or NULL if no
 *         node matches
 */
ctb_DNode_t * ctb_DList_find(
    ctb_DList_t * const                     self,
    ctb_DListIterator_FindPredicate_t const predicate
);

#endif // CTB_DLIST_H
