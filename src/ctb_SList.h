/**
 * @file
 */
#ifndef CTB_SLIST_H
#define CTB_SLIST_H
#include <stdbool.h>
#include <stddef.h>
/**
 * @ingroup ctb
 * @defgroup ctb_SList ctb_SList
 * @{
 */

/**
 * @brief Singly linked list type
 */
typedef struct ctb_SList ctb_SList_t;

#include "ctb_SListIterator.h"
#include "ctb_SNode.h"

/**
 * @brief Singly linked list data structure
 */
struct ctb_SList {
    ctb_SNode_t * first;  /**< Pointer to the first node */
    size_t        length; /**< Number of nodes currently in the list. */
};

/**
 * @brief Initializes a singly linked list
 *
 * @param self Pointer to a singly linked list
 * @return Pointer to the initialized singly linked list
 */
ctb_SList_t * ctb_SList_init(
    ctb_SList_t * const self
);

/**
 * @brief Adds a node at the specified index
 *
 * @param self Pointer to a singly linked list
 * @param node Pointer to the node to add
 * @param index Index where to add the node
 */
void ctb_SList_addByIndex(
    ctb_SList_t * const self,
    ctb_SNode_t * const node,
    size_t const        index
);

/**
 * @brief Adds a node at the beginning
 *
 * @param self Pointer to a singly linked list
 * @param node Pointer to the node to add
 */
void ctb_SList_addFirst(
    ctb_SList_t * const self,
    ctb_SNode_t * const node
);

/**
 * @brief Adds a node at the end
 *
 * @param self Pointer to a singly linked list
 * @param node Pointer to the node to add
 */
void ctb_SList_addLast(
    ctb_SList_t * const self,
    ctb_SNode_t * const node
);

/**
 * @brief Returns the node at the specified index
 *
 * @param self Pointer to a singly linked list
 * @param index Index of the node to return
 * @return Pointer to the node at the specified index
 */
ctb_SNode_t * ctb_SList_getByIndex(
    ctb_SList_t * const self,
    size_t const        index
);

/**
 * @brief Returns the first node
 *
 * @param self Pointer to a singly linked list
 * @return Pointer to the first node
 */
ctb_SNode_t * ctb_SList_getFirst(
    ctb_SList_t const * const self
);

/**
 * @brief Returns the last node
 *
 * @param self Pointer to a singly linked list
 * @return Pointer to the last node
 */
ctb_SNode_t * ctb_SList_getLast(
    ctb_SList_t const * const self
);

/**
 * @brief Returns the index of a node
 *
 * @param self Pointer to a singly linked list
 * @param node Pointer to the node
 * @return Index of the node, or SIZE_MAX if the node is not found
 */
size_t ctb_SList_getIndexOf(
    ctb_SList_t const * const self,
    ctb_SNode_t const * const node
);

/**
 * @brief Removes the node at the specified index
 *
 * @param self Pointer to a singly linked list
 * @param index Index of the node to remove
 * @return Pointer to the removed node
 */
ctb_SNode_t * ctb_SList_removeByIndex(
    ctb_SList_t * const self,
    size_t const        index
);

/**
 * @brief Removes the first node
 *
 * @param self Pointer to a singly linked list
 * @return Pointer to the removed node
 */
ctb_SNode_t * ctb_SList_removeFirst(
    ctb_SList_t * const self
);

/**
 * @brief Removes the last node
 *
 * @param self Pointer to a singly linked list
 * @return Pointer to the removed node
 */
ctb_SNode_t * ctb_SList_removeLast(
    ctb_SList_t * const self
);

/**
 * @brief Removes a node
 *
 * @param self Pointer to a singly linked list
 * @param node Pointer to the node to remove
 * @return Pointer to the removed node
 */
ctb_SNode_t * ctb_SList_remove(
    ctb_SList_t * const       self,
    ctb_SNode_t const * const node
);

/**
 * @brief Checks if the singly linked list is empty
 *
 * @param self Pointer to a singly linked list
 * @return True if the singly linked list is empty, false otherwise
 */
bool ctb_SList_isEmpty(
    ctb_SList_t const * const self
);

/**
 * @brief Returns the size of the singly linked list
 *
 * @param self Pointer to a singly linked list
 * @return Length of the singly linked list
 */
size_t ctb_SList_getLength(
    ctb_SList_t const * const self
);

/**
 * @brief Clears the singly linked list
 *
 * @param self Pointer to a singly linked list
 */
void ctb_SList_clear(
    ctb_SList_t * const self
);

/**
 * @brief Applies an operation to each node of the singly linked list
 *
 * @param self Pointer to a singly linked list
 * @param operation The function to apply to each node
 */
void ctb_SList_forEach(
    ctb_SList_t * const                        self,
    ctb_SListIterator_ForEachOperation_t const operation
);

/**
 * @brief Finds a node in the singly linked list that matches a predicate
 *
 * @param self Pointer to a singly linked list
 * @param predicate The predicate function to test each node
 * @return Pointer to the first matching node, or NULL if no match is found
 */
ctb_SNode_t * ctb_SList_find(
    ctb_SList_t * const                     self,
    ctb_SListIterator_FindPredicate_t const predicate
);

/** @} */
#endif // CTB_SLIST_H
