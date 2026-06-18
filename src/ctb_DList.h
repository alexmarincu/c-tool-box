/**
 * @defgroup ctb_DList ctb_DList
 * @ingroup ctb
 * @{
 * @file
 */
#ifndef CTB_DLIST_H
#define CTB_DLIST_H
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Doubly linked list type.
 */
typedef struct ctb_DList ctb_DList_t;

#include "ctb_DListIterator.h"
#include "ctb_DNode.h"

/**
 * @brief Doubly linked list data structure.
 */
struct ctb_DList {
    ctb_DNode_t * first;  /**< Pointer to the first node in the list. */
    ctb_DNode_t * last;   /**< Pointer to the last node in the list. */
    size_t        length; /**< Number of nodes currently in the list. */
};

/**
 * @brief Initializes a doubly linked list.
 *
 * @param self Pointer to the doubly linked list to initialize.
 * @return Pointer to the initialized doubly linked list (self).
 */
ctb_DList_t * ctb_DList_init(
    ctb_DList_t * const self
);

/**
 * @brief Adds a node at the specified index.
 *
 * @param self Pointer to the doubly linked list.
 * @param node Pointer to the node to add.
 * @param index The index at which to insert the node.
 */
void ctb_DList_addByIndex(
    ctb_DList_t * const self,
    ctb_DNode_t * const node,
    size_t const        index
);

/**
 * @brief Adds a node at the beginning of the list.
 *
 * @param self Pointer to the doubly linked list.
 * @param node Pointer to the node to add.
 */
void ctb_DList_addFirst(
    ctb_DList_t * const self,
    ctb_DNode_t * const node
);

/**
 * @brief Adds a node at the end of the list.
 *
 * @param self Pointer to the doubly linked list.
 * @param node Pointer to the node to add.
 */
void ctb_DList_addLast(
    ctb_DList_t * const self,
    ctb_DNode_t * const node
);

/**
 * @brief Returns the node at the specified index.
 *
 * @param self Pointer to the doubly linked list.
 * @param index Index of the node to return.
 * @return Pointer to the node at the specified index.
 */
ctb_DNode_t * ctb_DList_getByIndex(
    ctb_DList_t * const self,
    size_t              index
);

/**
 * @brief Returns the first node of the list.
 *
 * @param self Pointer to the doubly linked list.
 * @return Pointer to the first node, or NULL if the list is empty.
 */
ctb_DNode_t * ctb_DList_getFirst(
    ctb_DList_t const * const self
);

/**
 * @brief Returns the last node of the list.
 *
 * @param self Pointer to the doubly linked list.
 * @return Pointer to the last node, or NULL if the list is empty.
 */
ctb_DNode_t * ctb_DList_getLast(
    ctb_DList_t const * const self
);

/**
 * @brief Removes the node at the specified index.
 *
 * @param self Pointer to the doubly linked list.
 * @param index Index of the node to remove.
 * @return Pointer to the removed node.
 */
ctb_DNode_t * ctb_DList_removeByIndex(
    ctb_DList_t * const self,
    size_t const        index
);

/**
 * @brief Removes the first node of the list.
 *
 * @param self Pointer to the doubly linked list.
 * @return Pointer to the removed node, or NULL if the list was empty.
 */
ctb_DNode_t * ctb_DList_removeFirst(
    ctb_DList_t * const self
);

/**
 * @brief Removes the last node of the list.
 *
 * @param self Pointer to the doubly linked list.
 * @return Pointer to the removed node, or NULL if the list was empty.
 */
ctb_DNode_t * ctb_DList_removeLast(
    ctb_DList_t * const self
);

/**
 * @brief Removes a specific node from the list.
 *
 * @param self Pointer to the doubly linked list.
 * @param node Pointer to the node to remove.
 * @return Pointer to the removed node, or NULL if the node was not found in
 *         the list.
 */
ctb_DNode_t * ctb_DList_remove(
    ctb_DList_t * const self,
    ctb_DNode_t * const node
);

/**
 * @brief Returns the index of a specific node.
 *
 * @param self Pointer to the doubly linked list.
 * @param node Pointer to the node to find.
 * @return The index of the node, or SIZE_MAX if the node is not found.
 */
size_t ctb_DList_getIndexOf(
    ctb_DList_t * const       self,
    ctb_DNode_t const * const node
);

/**
 * @brief Checks if the doubly linked list is empty.
 *
 * @param self Pointer to the doubly linked list.
 * @return true if the list is empty, false otherwise.
 */
bool ctb_DList_isEmpty(
    ctb_DList_t const * const self
);

/**
 * @brief Returns the number of nodes in the doubly linked list.
 *
 * @param self Pointer to the doubly linked list.
 * @return The current length of the list.
 */
size_t ctb_DList_getLength(
    ctb_DList_t const * const self
);

/**
 * @brief Clears the doubly linked list.
 *
 * @param self Pointer to the doubly linked list to clear.
 */
void ctb_DList_clear(
    ctb_DList_t * const self
);

/**
 * @brief Applies an operation to each node of the doubly linked list.
 *
 * @param self Pointer to the doubly linked list.
 * @param operation The function to apply to each node.
 */
void ctb_DList_forEach(
    ctb_DList_t * const                        self,
    ctb_DListIterator_ForEachOperation_t const operation
);

/**
 * @brief Finds a node in the doubly linked list that matches a predicate.
 *
 * @param self Pointer to the doubly linked list.
 * @param predicate The predicate function to test each node.
 * @return Pointer to the first matching node, or NULL if no match is found.
 */
ctb_DNode_t * ctb_DList_find(
    ctb_DList_t * const                     self,
    ctb_DListIterator_FindPredicate_t const predicate
);

#endif // CTB_DLIST_H
/** @} */
