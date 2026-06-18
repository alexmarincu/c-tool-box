/**
 * @defgroup ctb_Array ctb_Array
 * @ingroup ctb
 * @{
 * @file
 */
#ifndef CTB_ARRAY_H
#define CTB_ARRAY_H
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Array type
 */
typedef struct ctb_Array ctb_Array_t;

#include "ctb.h"
#include "ctb_ArrayIterator.h"

/**
 * @brief Array data structure
 */
struct ctb_Array {
    void * items;    /**< Pointer to the raw array storage */
    size_t itemSize; /**< Size of each item in bytes */
    size_t capacity; /**< Total number of items the array can hold */
};

/**
 * @brief Helper macro to initialize an array from a raw array
 *
 * @param arr The raw array to initialize the array with
 * @return Pointer to a compound literal ctb_Array_t populated with the array's details
 */
#define ctb_Array(                       \
    arr                                  \
)                                        \
    (&(ctb_Array_t){                     \
        .items    = arr,                 \
        .itemSize = sizeof(arr[0]),      \
        .capacity = ctb_capacityOf(arr), \
    })

/**
 * @brief Initializes an array
 *
 * @param self Pointer to an array
 * @return Pointer to the initialized array
 */
ctb_Array_t * ctb_Array_init(
    ctb_Array_t * const self
);

/**
 * @brief Gets an item at the specified index
 *
 * @param self Pointer to an array
 * @param index Index of the item to get
 * @return Pointer to the item at the specified index, or NULL if index is out of bounds
 */
void * ctb_Array_get(
    ctb_Array_t const * const self,
    size_t const              index
);

/**
 * @brief Sets an item at the specified index
 *
 * @param self Pointer to an array
 * @param index Index of the item to set
 * @param value Pointer to the value to copy
 */
void ctb_Array_set(
    ctb_Array_t * const self,
    size_t const        index,
    void const * const  value
);

/**
 * @brief Gets the capacity of the array
 *
 * @param self Pointer to an array
 * @return Capacity of the array
 */
size_t ctb_Array_getCapacity(
    ctb_Array_t const * const self
);

/**
 * @brief Gets the size of each item in the array
 *
 * @param self Pointer to an array
 * @return Size of each item in bytes
 */
size_t ctb_Array_getItemSize(
    ctb_Array_t const * const self
);

/**
 * @brief Applies an operation to each item of the array
 *
 * @param self Pointer to an array
 * @param operation The function to apply to each item
 */
void ctb_Array_forEach(
    ctb_Array_t const * const                  self,
    ctb_ArrayIterator_ForEachOperation_t const operation
);

/**
 * @brief Finds an item in the array that matches a predicate
 *
 * @param self Pointer to an array
 * @param predicate The predicate function to test each item
 * @return Pointer to the first matching item, or NULL if no match is found
 */
void * ctb_Array_find(
    ctb_Array_t const * const               self,
    ctb_ArrayIterator_FindPredicate_t const predicate
);

#endif // CTB_ARRAY_H
/** @} */
