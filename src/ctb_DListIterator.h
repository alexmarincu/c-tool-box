/**
 * @file
 */
#ifndef CTB_DLISTITERATOR_H
#define CTB_DLISTITERATOR_H

/**
 * @brief Doubly linked list iterator type
 */
typedef struct ctb_DListIterator ctb_DListIterator_t;

#include "ctb_DNode.h"
#include <stdbool.h>

/**
 * @brief Typedef for predicate function used to find a node in the doubly linked list
 *
 * @param node Pointer to the node
 * @return True if the node satisfies the predicate, false otherwise
 */
typedef bool (*ctb_DListIterator_FindPredicate_t)(ctb_DNode_t * const node);

/**
 * @brief Typedef for operation function to be applied to each node in the doubly linked list
 *
 * @param node Pointer to the node
 */
typedef void (*ctb_DListIterator_ForEachOperation_t)(ctb_DNode_t * const node);

#include "ctb_DList.h"

/**
 * @brief Doubly linked list iterator data structure
 */
struct ctb_DListIterator {
    ctb_DList_t * list;    /**< Pointer to the doubly linked list */
    ctb_DNode_t * current; /**< Pointer to the current node */
};

/**
 * @brief Initializes a doubly linked list iterator
 *
 * @param self Pointer to a doubly linked list iterator
 * @param list Pointer to the doubly linked list
 * @return Pointer to the initialized doubly linked list iterator
 */
ctb_DListIterator_t * ctb_DListIterator_init(
    ctb_DListIterator_t * const self, ctb_DList_t * const list
);

/**
 * @brief Resets the iterator to the first node
 *
 * @param self Pointer to a doubly linked list iterator
 * @return Pointer to the doubly linked list iterator reset to the first node
 */
ctb_DListIterator_t * ctb_DListIterator_resetToFirst(
    ctb_DListIterator_t * const self
);

/**
 * @brief Resets the iterator to the last node
 *
 * @param self Pointer to a doubly linked list iterator
 * @return Pointer to the doubly linked list iterator reset to the last node
 */
ctb_DListIterator_t * ctb_DListIterator_resetToLast(
    ctb_DListIterator_t * const self
);

/**
 * @brief Checks if there is a node after the current node
 *
 * @param self Pointer to a doubly linked list iterator
 * @return True if there is a node after the current node, false otherwise
 */
bool ctb_DListIterator_hasNext(ctb_DListIterator_t * const self);

/**
 * @brief Checks if there is a node before the current node
 *
 * @param self Pointer to a doubly linked list iterator
 * @return True if there is a node before the current node, false otherwise
 */
bool ctb_DListIterator_hasPrevious(ctb_DListIterator_t * const self);

/**
 * @brief Returns the next node
 *
 * @param self Pointer to a doubly linked list iterator
 * @return Pointer to the next node, or NULL if there is no next node
 */
ctb_DNode_t * ctb_DListIterator_next(ctb_DListIterator_t * const self);

/**
 * @brief Returns the previous node
 *
 * @param self Pointer to a doubly linked list iterator
 * @return Pointer to the previous node, or NULL if there is no previous node
 */
ctb_DNode_t * ctb_DListIterator_previous(ctb_DListIterator_t * const self);

/**
 * @brief Applies an operation to each node in the doubly linked list
 *
 * @param self Pointer to a doubly linked list iterator
 * @param operation Operation to apply to each node
 */
void ctb_DListIterator_forEach(
    ctb_DListIterator_t * const                self,
    ctb_DListIterator_ForEachOperation_t const operation
);

/**
 * @brief Finds a node in the doubly linked list that satisfies a predicate
 *
 * @param self Pointer to a doubly linked list iterator
 * @param predicate Predicate function
 * @return Pointer to the found node, or NULL if no node satisfies the predicate
 */
ctb_DNode_t * ctb_DListIterator_find(
    ctb_DListIterator_t * const             self,
    ctb_DListIterator_FindPredicate_t const predicate
);

#endif // CTB_DLISTITERATOR_H
