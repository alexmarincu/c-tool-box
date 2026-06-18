/**
 * @file
 */
#ifndef CTB_QUEUEARRAY_H
#define CTB_QUEUEARRAY_H
#include <stdbool.h>
#include <stddef.h>
/**
 * @ingroup ctb
 * @defgroup ctb_QueueArray ctb_QueueArray
 * @{
 */

/**
 * @brief QueueArray type
 */
typedef struct ctb_QueueArray ctb_QueueArray_t;

#include "ctb_Array.h"

/**
 * @brief QueueArray data structure
 */
struct ctb_QueueArray {
    ctb_Array_t array;  /**< Underlying array storage */
    size_t      head;   /**< Front index for dequeue operations */
    size_t      tail;   /**< Back index for enqueue operations */
    size_t      length; /**< Number of elements currently in the queue */
};

/**
 * @brief Helper macro to initialize a QueueArray from a raw array
 *
 * @param arr The raw array to initialize the QueueArray with
 * @return Pointer to a compound literal ctb_QueueArray_t initialized with the array's details and zero state
 */
#define ctb_QueueArray(              \
    arr                              \
)                                    \
    (&(ctb_QueueArray_t){            \
        .array  = *(ctb_Array(arr)), \
        .head   = 0,                 \
        .tail   = 0,                 \
        .length = 0,                 \
    })

/**
 * @brief Initializes a QueueArray
 *
 * @param self Pointer to a QueueArray
 * @return Pointer to the initialized QueueArray
 */
ctb_QueueArray_t * ctb_QueueArray_init(
    ctb_QueueArray_t * const self
);

/**
 * @brief Enqueues a value into the queue
 *
 * Copies the value into the queue storage at the tail position.
 *
 * @param self Pointer to a QueueArray
 * @param value Pointer to the value to copy
 * @return Pointer to the stored element, or NULL if the queue is full
 */
void * ctb_QueueArray_enqueue(
    ctb_QueueArray_t * const self,
    void const * const       value
);

/**
 * @brief Dequeues the front value from the queue
 *
 * Returns a pointer to the slot being vacated. The caller may read
 * the data from this pointer before it is overwritten by a subsequent enqueue.
 *
 * @param self Pointer to a QueueArray
 * @return Pointer to the removed element, or NULL if the queue is empty
 */
void * ctb_QueueArray_dequeue(
    ctb_QueueArray_t * const self
);

/**
 * @brief Peeks at the front value of the queue without removing it
 *
 * @param self Pointer to a QueueArray
 * @return Pointer to the front element, or NULL if the queue is empty
 */
void * ctb_QueueArray_peek(
    ctb_QueueArray_t const * const self
);

/**
 * @brief Checks if the queue is empty
 *
 * @param self Pointer to a QueueArray
 * @return True if the queue is empty, false otherwise
 */
bool ctb_QueueArray_isEmpty(
    ctb_QueueArray_t const * const self
);

/**
 * @brief Gets the number of elements in the queue
 *
 * @param self Pointer to a QueueArray
 * @return Number of elements in the queue
 */
size_t ctb_QueueArray_getLength(
    ctb_QueueArray_t const * const self
);

/**
 * @brief Gets the maximum capacity of the queue
 *
 * @param self Pointer to a QueueArray
 * @return Maximum number of elements the queue can hold
 */
size_t ctb_QueueArray_getCapacity(
    ctb_QueueArray_t const * const self
);

/**
 * @brief Clears all elements from the queue
 *
 * @param self Pointer to a QueueArray
 */
void ctb_QueueArray_clear(
    ctb_QueueArray_t * const self
);

/** @} */
#endif // CTB_QUEUEARRAY_H
