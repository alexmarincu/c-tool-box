/**
 * @file
 */
#ifndef CTB_STACKLIST_H
#define CTB_STACKLIST_H
/**
 * @ingroup ctb
 * @defgroup ctb_StackList ctb_StackList
 * @{
 */

/**
 * @brief Stack (list-backed) type definition.
 */
typedef struct ctb_StackList ctb_StackList_t;

#include "ctb_SList.h"

/**
 * @brief Stack (list-backed) structure.
 */
struct ctb_StackList {
    ctb_SList_t list; /**< Underlying single linked list. */
};

/**
 * @brief Initializes the stack.
 *
 * @param self Pointer to the stack instance.
 * @return Pointer to the initialized stack instance.
 */
ctb_StackList_t * ctb_StackList_init(
    ctb_StackList_t * const self
);

/**
 * @brief Pushes a node onto the stack.
 *
 * @param self Pointer to the stack instance.
 * @param node Pointer to the node to push.
 */
void ctb_StackList_push(
    ctb_StackList_t * const self,
    ctb_SNode_t * const     node
);

/**
 * @brief Pops a node from the stack.
 *
 * @param self Pointer to the stack instance.
 * @return Pointer to the popped node, or NULL if the stack is empty.
 */
ctb_SNode_t * ctb_StackList_pop(
    ctb_StackList_t * const self
);

/**
 * @brief Peeks at the top node of the stack.
 *
 * @param self Pointer to the stack instance.
 * @return Pointer to the top node, or NULL if the stack is empty.
 */
ctb_SNode_t * ctb_StackList_peek(
    ctb_StackList_t const * const self
);

/**
 * @brief Checks if the stack is empty.
 *
 * @param self Pointer to the stack instance.
 * @return True if the stack is empty, false otherwise.
 */
bool ctb_StackList_isEmpty(
    ctb_StackList_t const * const self
);

/**
 * @brief Clears the stack.
 *
 * @param self Pointer to the stack instance.
 */
void ctb_StackList_clear(
    ctb_StackList_t * const self
);

/** @} */
#endif // CTB_STACKLIST_H
