/**
 * @file
 */
#ifndef CTB_QUEUE_H
#define CTB_QUEUE_H

/**
 * @brief Queue type
 */
typedef struct ctb_Queue ctb_Queue_t;

#include "ctb_DList.h"
#include <stdbool.h>

/**
 * @brief Queue data structure
 */
struct ctb_Queue {
    ctb_DList_t list;
};

/**
 * @brief Initializes a queue
 *
 * @param self Pointer to a queue
 * @return Pointer to the initialized queue
 */
ctb_Queue_t * ctb_Queue_init(ctb_Queue_t * const self);

/**
 * @brief Checks if the queue is empty
 *
 * @param self Pointer to a queue
 * @return True if the queue is empty, false otherwise
 */
bool ctb_Queue_isEmpty(ctb_Queue_t * const self);

/**
 * @brief Adds a node at the end of the queue
 *
 * @param self Pointer to a queue
 * @param node Pointer to the node to add
 */
void ctb_Queue_enqueue(
    ctb_Queue_t * const self, ctb_DNode_t * const node
);

/**
 * @brief Removes and returns the first node from the queue
 *
 * @param self Pointer to a queue
 * @return Pointer to the first node in the queue
 */
ctb_DNode_t * ctb_Queue_dequeue(ctb_Queue_t * const self);

/**
 * @brief Clears the queue
 *
 * @param self Pointer to a queue
 */
void ctb_Queue_clear(ctb_Queue_t * const self);

#endif // CTB_QUEUE_H
