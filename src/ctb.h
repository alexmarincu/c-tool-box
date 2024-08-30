/**
 * @file
 */
#ifndef CTB_H
#define CTB_H

/**
 * @brief Creates an array of the given type and length
 *
 * @param itemType Type of each item in the array
 * @param length Number of items in the array
 */
#define ctb_arr(itemType, length) \
    ((itemType[length]){ 0 })

/**
 * @brief Creates an object of the given type and initializes it with zeros
 *
 * @param type Type of the object
 */
#define ctb_obj(type) \
    ((type){ 0 })

/**
 * @brief Calculates the length of the given array
 *
 * @param arr Array to calculate the length from
 */
#define ctb_lengthOf(arr) \
    (sizeof(arr) / sizeof(arr[0]))

/**
 * @brief Calculates the address of the containing object
 *
 * @param obj Object to calculate the containing object from
 * @param type Type of the containing object
 * @param member Member of the containing object
 */
#define ctb_containerOf(obj, type, member) \
    ((type *)((char *)(obj) - offsetof(type, member)))

/**
 * @brief Generates a compile-time assertion
 *
 * @param expression Expression to assert
 * @param identifier Identifier to use in the assertion
 */
#define ctb_staticAssert(expression, identifier) \
    typedef char identifier[(!!(expression)) * 2 - 1]

#endif // CTB_H
