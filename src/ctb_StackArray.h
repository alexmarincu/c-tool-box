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
 * @brief Stack (array-backed) type definition.
 */
typedef struct ctb_StackArray ctb_StackArray_t;

#include "ctb_Array.h"
#include "ctb_ArrayIterator.h"

/**
 * @brief Stack (array-backed) structure.
 */
struct ctb_StackArray {
    ctb_Array_t array;  /**< Underlying array storage. */
    size_t      length; /**< Number of elements currently in the stack. */
};

/**
 * @brief Initializes a stack array from a raw array.
 *
 * @param arr The raw array to back the stack.
 * @return Pointer to a compound literal ctb_StackArray_t initialized with the
 *         array and zero length.
 */
#define ctb_StackArray(                    \
    arr                                    \
)                                          \
    (&(ctb_StackArray_t){                  \
        .array  = *(ctb_Array(arr)),       \
        .length = 0,                       \
    })

/**
 * @brief Initializes a stack array.
 *
 * @param self Pointer to the stack array instance.
 * @return Pointer to the initialized stack array instance.
 */
ctb_StackArray_t * ctb_StackArray_init(
    ctb_StackArray_t * const self
);

/**
 * @brief Checks if the stack array is empty.
 *
 * @param self Pointer to the stack array instance.
 * @return True if the stack array is empty, false otherwise.
 */
bool ctb_StackArray_isEmpty(
    ctb_StackArray_t const * const self
);

/**
 * @brief Returns the number of elements in the stack array.
 *
 * @param self Pointer to the stack array instance.
 * @return Number of elements currently in the stack array.
 */
size_t ctb_StackArray_getLength(
    ctb_StackArray_t const * const self
);

/**
 * @brief Returns the maximum capacity of the stack array.
 *
 * @param self Pointer to the stack array instance.
 * @return Maximum number of elements the stack array can hold.
 */
size_t ctb_StackArray_getCapacity(
    ctb_StackArray_t const * const self
);

/**
 * @brief Pushes a value onto the stack array.
 *
 * Copies the value into storage. Asserts if the stack is full.
 *
 * @param self Pointer to the stack array instance.
 * @param value Pointer to the value to push.
 */
void ctb_StackArray_push(
    ctb_StackArray_t * const self,
    void const * const       value
);

/**
 * @brief Pops the top value from the stack array.
 *
 * @param self Pointer to the stack array instance.
 * @return Pointer to the popped element, or NULL if the stack is empty.
 */
void * ctb_StackArray_pop(
    ctb_StackArray_t * const self
);

/**
 * @brief Returns the top value without removing it.
 *
 * @param self Pointer to the stack array instance.
 * @return Pointer to the top element, or NULL if the stack is empty.
 */
void * ctb_StackArray_peek(
    ctb_StackArray_t const * const self
);

/**
 * @brief Removes all elements from the stack array.
 *
 * @param self Pointer to the stack array instance.
 */
void ctb_StackArray_clear(
    ctb_StackArray_t * const self
);

/**
 * @brief Applies an operation to each element of the stack array.
 *
 * @param self Pointer to the stack array instance.
 * @param operation The function to apply to each element.
 */
void ctb_StackArray_forEach(
    ctb_StackArray_t const * const                  self,
    ctb_ArrayIterator_ForEachOperation_t const operation
);

/**
 * @brief Finds an element in the stack array that matches a predicate.
 *
 * @param self Pointer to the stack array instance.
 * @param predicate The predicate function to test each element.
 * @return Pointer to the first matching element, or NULL if no match is found.
 */
void * ctb_StackArray_find(
    ctb_StackArray_t const * const               self,
    ctb_ArrayIterator_FindPredicate_t const predicate
);

/** @} */
#endif // CTB_STACKARRAY_H
