/**
 * @file
 */
#ifndef CTB_QUEUE_ARRAY_H
#define CTB_QUEUE_ARRAY_H
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
 * @brief QueueArray data structure backed by a ring buffer
 */
struct ctb_QueueArray {
    ctb_Array_t array;  /**< Underlying array storage */
    size_t      head;   /**< Index of the front element */
    size_t      tail;   /**< Index where the next element will be inserted */
    size_t      length; /**< Current number of elements */
};

/**
 * @brief Helper macro to initialize a QueueArray from a raw array
 *
 * @param arr The raw array to initialize the QueueArray with
 * @return Pointer to a compound literal ctb_QueueArray_t
 */
#define ctb_QueueArray(        \
    arr                        \
)                              \
    (&(ctb_QueueArray_t){      \
        .array  = *(ctb_Array(arr)), \
        .head   = 0,           \
        .tail   = 0,           \
        .length = 0,           \
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
 * @brief Checks if the QueueArray is empty
 *
 * @param self Pointer to a QueueArray
 * @return True if the QueueArray is empty, false otherwise
 */
bool ctb_QueueArray_isEmpty(
    ctb_QueueArray_t const * const self
);

/**
 * @brief Gets the number of elements in the QueueArray
 *
 * @param self Pointer to a QueueArray
 * @return Number of elements in the QueueArray
 */
size_t ctb_QueueArray_getLength(
    ctb_QueueArray_t const * const self
);

/**
 * @brief Gets the capacity of the QueueArray
 *
 * @param self Pointer to a QueueArray
 * @return Maximum number of elements the QueueArray can hold
 */
size_t ctb_QueueArray_getCapacity(
    ctb_QueueArray_t const * const self
);

/**
 * @brief Adds an element to the end of the queue
 *
 * @param self Pointer to a QueueArray
 * @param value Pointer to the value to copy into the queue
 */
void ctb_QueueArray_enqueue(
    ctb_QueueArray_t * const self,
    void const * const       value
);

/**
 * @brief Removes and returns the front element from the queue
 *
 * @param self Pointer to a QueueArray
 * @return Pointer to the removed front element, or NULL if the queue is empty
 */
void * ctb_QueueArray_dequeue(
    ctb_QueueArray_t * const self
);

/**
 * @brief Returns the front element without removing it
 *
 * @param self Pointer to a QueueArray
 * @return Pointer to the front element, or NULL if the queue is empty
 */
void * ctb_QueueArray_peek(
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
#endif // CTB_QUEUE_ARRAY_H
