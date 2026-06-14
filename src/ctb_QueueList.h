/**
 * @file
 */
#ifndef CTB_QUEUELIST_H
#define CTB_QUEUELIST_H
#include <stdbool.h>
/**
 * @ingroup ctb
 * @defgroup ctb_QueueList ctb_QueueList
 * @{
 */

/**
 * @brief Queue (list-backed) type
 */
typedef struct ctb_QueueList ctb_QueueList_t;

#include "ctb_DList.h"

/**
 * @brief Queue (list-backed) data structure
 */
struct ctb_QueueList {
    ctb_DList_t list; /**< Underlying doubly linked list to store the queue elements. */
};

/**
 * @brief Initializes a queue
 *
 * @param self Pointer to a queue
 * @return Pointer to the initialized queue
 */
ctb_QueueList_t * ctb_QueueList_init(
    ctb_QueueList_t * const self
);

/**
 * @brief Checks if the queue is empty
 *
 * @param self Pointer to a queue
 * @return True if the queue is empty, false otherwise
 */
bool ctb_QueueList_isEmpty(
    ctb_QueueList_t * const self
);

/**
 * @brief Adds a node at the end of the queue
 *
 * @param self Pointer to a queue
 * @param node Pointer to the node to add
 */
void ctb_QueueList_enqueue(
    ctb_QueueList_t * const self,
    ctb_DNode_t * const     node
);

/**
 * @brief Removes and returns the first node from the queue
 *
 * @param self Pointer to a queue
 * @return Pointer to the first node in the queue
 */
ctb_DNode_t * ctb_QueueList_dequeue(
    ctb_QueueList_t * const self
);

/**
 * @brief Clears the queue
 *
 * @param self Pointer to a queue
 */
void ctb_QueueList_clear(
    ctb_QueueList_t * const self
);

/** @} */
#endif // CTB_QUEUELIST_H
