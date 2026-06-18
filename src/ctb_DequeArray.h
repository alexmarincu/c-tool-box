/**
 * @file
 */
#ifndef CTB_DEQUEARRAY_H
#define CTB_DEQUEARRAY_H
#include <stdbool.h>
#include <stddef.h>
/**
 * @ingroup ctb
 * @defgroup ctb_DequeArray ctb_DequeArray
 * @{
 */

/**
 * @brief DequeArray type
 */
typedef struct ctb_DequeArray ctb_DequeArray_t;

#include "ctb_Array.h"

/**
 * @brief DequeArray data structure
 */
struct ctb_DequeArray {
    ctb_Array_t array;  /**< Underlying array storage */
    size_t      head;   /**< Front index for popFirst/pushFirst operations */
    size_t      tail;   /**< Back index for pushLast/popLast operations */
    size_t      length; /**< Number of elements currently in the deque */
};

/**
 * @brief Helper macro to initialize a DequeArray from a raw array
 *
 * @param arr The raw array to initialize the DequeArray with
 * @return Pointer to a compound literal ctb_DequeArray_t initialized with the array's details and zero state
 */
#define ctb_DequeArray(              \
    arr                              \
)                                    \
    (&(ctb_DequeArray_t){            \
        .array  = *(ctb_Array(arr)), \
        .head   = 0,                 \
        .tail   = 0,                 \
        .length = 0,                 \
    })

/**
 * @brief Initializes a DequeArray
 *
 * @param self Pointer to a DequeArray
 * @return Pointer to the initialized DequeArray
 */
ctb_DequeArray_t * ctb_DequeArray_init(
    ctb_DequeArray_t * const self
);

/**
 * @brief Pushes a value onto the front of the deque
 *
 * Copies the value into the deque storage at the head position.
 *
 * @param self Pointer to a DequeArray
 * @param value Pointer to the value to copy
 * @return Pointer to the stored element, or NULL if the deque is full
 */
void * ctb_DequeArray_pushFirst(
    ctb_DequeArray_t * const self,
    void const * const       value
);

/**
 * @brief Pushes a value onto the back of the deque
 *
 * Copies the value into the deque storage at the tail position.
 *
 * @param self Pointer to a DequeArray
 * @param value Pointer to the value to copy
 * @return Pointer to the stored element, or NULL if the deque is full
 */
void * ctb_DequeArray_pushLast(
    ctb_DequeArray_t * const self,
    void const * const       value
);

/**
 * @brief Pops the front value from the deque
 *
 * Returns a pointer to the slot being vacated. The caller may read
 * the data from this pointer before it is overwritten by a subsequent push.
 *
 * @param self Pointer to a DequeArray
 * @return Pointer to the removed element, or NULL if the deque is empty
 */
void * ctb_DequeArray_popFirst(
    ctb_DequeArray_t * const self
);

/**
 * @brief Pops the back value from the deque
 *
 * Returns a pointer to the slot being vacated. The caller may read
 * the data from this pointer before it is overwritten by a subsequent push.
 *
 * @param self Pointer to a DequeArray
 * @return Pointer to the removed element, or NULL if the deque is empty
 */
void * ctb_DequeArray_popLast(
    ctb_DequeArray_t * const self
);

/**
 * @brief Peeks at the front value of the deque without removing it
 *
 * @param self Pointer to a DequeArray
 * @return Pointer to the front element, or NULL if the deque is empty
 */
void * ctb_DequeArray_peekFirst(
    ctb_DequeArray_t const * const self
);

/**
 * @brief Peeks at the back value of the deque without removing it
 *
 * @param self Pointer to a DequeArray
 * @return Pointer to the back element, or NULL if the deque is empty
 */
void * ctb_DequeArray_peekLast(
    ctb_DequeArray_t const * const self
);

/**
 * @brief Checks if the deque is empty
 *
 * @param self Pointer to a DequeArray
 * @return True if the deque is empty, false otherwise
 */
bool ctb_DequeArray_isEmpty(
    ctb_DequeArray_t const * const self
);

/**
 * @brief Gets the number of elements in the deque
 *
 * @param self Pointer to a DequeArray
 * @return Number of elements in the deque
 */
size_t ctb_DequeArray_getLength(
    ctb_DequeArray_t const * const self
);

/**
 * @brief Gets the maximum capacity of the deque
 *
 * @param self Pointer to a DequeArray
 * @return Maximum number of elements the deque can hold
 */
size_t ctb_DequeArray_getCapacity(
    ctb_DequeArray_t const * const self
);

/**
 * @brief Clears all elements from the deque
 *
 * @param self Pointer to a DequeArray
 */
void ctb_DequeArray_clear(
    ctb_DequeArray_t * const self
);

/** @} */
#endif // CTB_DEQUEARRAY_H
