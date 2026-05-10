/**
 * @file
 */
#ifndef CTB_SLISTITERATOR_H
#define CTB_SLISTITERATOR_H
#include <stdbool.h>
/**
 * @ingroup ctb
 * @defgroup ctb_SListIterator ctb_SListIterator
 * @{
 */

/**
 * @brief Singly linked list iterator type.
 */
typedef struct ctb_SListIterator ctb_SListIterator_t;

#include "ctb_SNode.h"

/**
 * @brief Typedef for predicate function used to find a node in the singly
 *        linked list.
 *
 * @param node Pointer to the node to test.
 * @return true if the node satisfies the predicate, false otherwise.
 */
typedef bool (*ctb_SListIterator_FindPredicate_t)(ctb_SNode_t * const node);

/**
 * @brief Typedef for operation function to be applied to each node in the
 *        singly linked list.
 *
 * @param node Pointer to the node to operate on.
 */
typedef void (*ctb_SListIterator_ForEachOperation_t)(ctb_SNode_t * const node);

#include "ctb_SList.h"

/**
 * @brief Singly linked list iterator data structure.
 */
struct ctb_SListIterator {
    ctb_SList_t * list;     /**< Pointer to the singly linked list. */
    ctb_SNode_t * nextNode; /**< Pointer to the next node in the iteration. */
};

/**
 * @brief Initializes a singly linked list iterator.
 *
 * @param self Pointer to the singly linked list iterator to initialize.
 * @param list Pointer to the singly linked list to iterate over.
 * @return Pointer to the initialized singly linked list iterator (self).
 */
ctb_SListIterator_t * ctb_SListIterator_init(
    ctb_SListIterator_t * const self,
    ctb_SList_t * const         list
);

/**
 * @brief Resets the iterator to the first node.
 *
 * @param self Pointer to the singly linked list iterator.
 * @return Pointer to the singly linked list iterator (self).
 */
ctb_SListIterator_t * ctb_SListIterator_resetToFirst(
    ctb_SListIterator_t * const self
);

/**
 * @brief Checks if there is a node after the current node.
 *
 * @param self Pointer to the singly linked list iterator.
 * @return true if there is a next node, false otherwise.
 */
bool ctb_SListIterator_hasNext(
    ctb_SListIterator_t const * const self
);

/**
 * @brief Returns the next node and advances the iterator.
 *
 * @param self Pointer to the singly linked list iterator.
 * @return Pointer to the next node, or NULL if there are no more nodes.
 */
ctb_SNode_t * ctb_SListIterator_next(
    ctb_SListIterator_t * const self
);

/**
 * @brief Applies an operation to each node in the singly linked list.
 *
 * @param self Pointer to the singly linked list iterator.
 * @param operation The operation to apply to each node.
 */
void ctb_SListIterator_forEach(
    ctb_SListIterator_t * const                self,
    ctb_SListIterator_ForEachOperation_t const operation
);

/**
 * @brief Finds a node in the singly linked list that satisfies a predicate.
 *
 * @param self Pointer to the singly linked list iterator.
 * @param predicate The predicate function to test each node.
 * @return Pointer to the first matching node, or NULL if no match is found.
 */
ctb_SNode_t * ctb_SListIterator_find(
    ctb_SListIterator_t * const             self,
    ctb_SListIterator_FindPredicate_t const predicate
);

/** @} */
#endif // CTB_SLISTITERATOR_H
