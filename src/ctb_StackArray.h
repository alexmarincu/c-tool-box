/**
 * @file
 */
#ifndef CTB_STACKARRAY_H
#define CTB_STACKARRAY_H
#include <stdbool.h>
#include <stddef.h>
/**
 * @ingroup ctb
 * @defgroup ctb_StackArray ctb_StackArray
 * @{
 */

/**
 * @brief StackArray type
 */
typedef struct ctb_StackArray ctb_StackArray_t;

#include "ctb_Array.h"

/**
 * @brief StackArray data structure
 */
struct ctb_StackArray {
    ctb_Array_t array;  /**< Underlying array storage */
    size_t      length; /**< Number of elements currently in the stack */
};

/**
 * @brief Helper macro to initialize a StackArray from a raw array
 *
 * @param arr The raw array to initialize the StackArray with
 * @return Pointer to a compound literal ctb_StackArray_t initialized with the array's details and zero length
 */
#define ctb_StackArray(              \
    arr                              \
)                                    \
    (&(ctb_StackArray_t){            \
        .array  = *(ctb_Array(arr)), \
        .length = 0,                 \
    })

/**
 * @brief Initializes a StackArray
 *
 * @param self Pointer to a StackArray
 * @return Pointer to the initialized StackArray
 */
ctb_StackArray_t * ctb_StackArray_init(
    ctb_StackArray_t * const self
);

/**
 * @brief Pushes a value onto the stack
 *
 * Copies the value into the stack storage at the top position.
 *
 * @param self Pointer to a StackArray
 * @param value Pointer to the value to copy
 * @return Pointer to the stored element, or NULL if the stack is full
 */
void * ctb_StackArray_push(
    ctb_StackArray_t * const self,
    void const * const       value
);

/**
 * @brief Pops the top value from the stack
 *
 * Returns a pointer to the slot being vacated. The caller may read
 * the data from this pointer before it is overwritten by a subsequent push.
 *
 * @param self Pointer to a StackArray
 * @return Pointer to the removed element, or NULL if the stack is empty
 */
void * ctb_StackArray_pop(
    ctb_StackArray_t * const self
);

/**
 * @brief Peeks at the top value of the stack without removing it
 *
 * @param self Pointer to a StackArray
 * @return Pointer to the top element, or NULL if the stack is empty
 */
void * ctb_StackArray_peek(
    ctb_StackArray_t const * const self
);

/**
 * @brief Checks if the stack is empty
 *
 * @param self Pointer to a StackArray
 * @return True if the stack is empty, false otherwise
 */
bool ctb_StackArray_isEmpty(
    ctb_StackArray_t const * const self
);

/**
 * @brief Gets the number of elements in the stack
 *
 * @param self Pointer to a StackArray
 * @return Number of elements in the stack
 */
size_t ctb_StackArray_getLength(
    ctb_StackArray_t const * const self
);

/**
 * @brief Clears all elements from the stack
 *
 * @param self Pointer to a StackArray
 */
void ctb_StackArray_clear(
    ctb_StackArray_t * const self
);

/** @} */
#endif // CTB_STACKARRAY_H
