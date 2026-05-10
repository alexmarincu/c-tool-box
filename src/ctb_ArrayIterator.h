/**
 * @file
 */
#ifndef CTB_ARRAYITERATOR_H
#define CTB_ARRAYITERATOR_H
#include <stdbool.h>
#include <stddef.h>
/**
 * @ingroup ctb_Array
 * @defgroup ctb_ArrayIterator ctb_ArrayIterator
 * @{
 */

/**
 * @brief Typedef for predicate function used to find an item in the array.
 *
 * @param item Pointer to the item to test.
 * @return true if the item satisfies the predicate, false otherwise.
 */
typedef bool (*ctb_ArrayIterator_FindPredicate_t)(void * const item);

/**
 * @brief Typedef for operation function to be applied to each item in the
 *        array.
 *
 * @param item Pointer to the item to operate on.
 */
typedef void (*ctb_ArrayIterator_ForEachOperation_t)(void * const item);

/**
 * @brief Array iterator type
 */
typedef struct ctb_ArrayIterator ctb_ArrayIterator_t;

#include "ctb_Array.h"

/**
 * @brief Array iterator data structure
 */
struct ctb_ArrayIterator {
    ctb_Array_t const * array;     /**< Pointer to the array being iterated */
    size_t              nextIndex; /**< Next index in the array */
};

/**
 * @brief Initializes an array iterator
 *
 * @param self Pointer to an array iterator
 * @param array Pointer to the array to iterate over
 * @return Pointer to the initialized array iterator
 */
ctb_ArrayIterator_t * ctb_ArrayIterator_init(
    ctb_ArrayIterator_t * const self,
    ctb_Array_t const * const   array
);

/**
 * @brief Checks if the array iterator has a next item
 *
 * @param self Pointer to an array iterator
 * @return True if there is a next item, false otherwise
 */
bool ctb_ArrayIterator_hasNext(
    ctb_ArrayIterator_t const * const self
);

/**
 * @brief Gets the next item from the array iterator
 *
 * @param self Pointer to an array iterator
 * @return Pointer to the next item, or NULL if no next item
 */
void * ctb_ArrayIterator_next(
    ctb_ArrayIterator_t * const self
);

/**
 * @brief Resets the array iterator to the beginning of the array
 *
 * @param self Pointer to an array iterator
 */
void ctb_ArrayIterator_reset(
    ctb_ArrayIterator_t * const self
);

/**
 * @brief Applies an operation to each item of the array using an iterator
 *
 * @param self Pointer to an array iterator
 * @param operation The function to apply to each item
 */
void ctb_ArrayIterator_forEach(
    ctb_ArrayIterator_t * const                self,
    ctb_ArrayIterator_ForEachOperation_t const operation
);

/**
 * @brief Finds an item in the array that matches a predicate using an iterator
 *
 * @param self Pointer to an array iterator
 * @param predicate The predicate function to test each item
 * @return Pointer to the first matching item, or NULL if no match is found
 */
void * ctb_ArrayIterator_find(
    ctb_ArrayIterator_t * const             self,
    ctb_ArrayIterator_FindPredicate_t const predicate
);

/** @} */

#endif // CTB_ARRAYITERATOR_H
