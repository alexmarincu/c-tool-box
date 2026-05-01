/**
 * @file
 */
#ifndef CTB_STACK_H
#define CTB_STACK_H
/**
 * @ingroup ctb
 * @defgroup ctb_Stack ctb_Stack
 * @{
 */

/**
 * @brief Stack type definition.
 */
typedef struct ctb_Stack ctb_Stack_t;

#include "ctb_SList.h"

/**
 * @brief Stack structure.
 */
struct ctb_Stack {
    ctb_SList_t list; /**< Underlying single linked list. */
};

/**
 * @brief Initializes the stack.
 *
 * @param self Pointer to the stack instance.
 * @return Pointer to the initialized stack instance.
 */
ctb_Stack_t * ctb_Stack_init(
    ctb_Stack_t * const self
);

/**
 * @brief Pushes a node onto the stack.
 *
 * @param self Pointer to the stack instance.
 * @param node Pointer to the node to push.
 */
void ctb_Stack_push(
    ctb_Stack_t * const self,
    ctb_SNode_t * const node
);

/**
 * @brief Pops a node from the stack.
 *
 * @param self Pointer to the stack instance.
 * @return Pointer to the popped node, or NULL if the stack is empty.
 */
ctb_SNode_t * ctb_Stack_pop(
    ctb_Stack_t * const self
);

/**
 * @brief Peeks at the top node of the stack.
 *
 * @param self Pointer to the stack instance.
 * @return Pointer to the top node, or NULL if the stack is empty.
 */
ctb_SNode_t * ctb_Stack_peek(
    ctb_Stack_t const * const self
);

/**
 * @brief Checks if the stack is empty.
 *
 * @param self Pointer to the stack instance.
 * @return True if the stack is empty, false otherwise.
 */
bool ctb_Stack_isEmpty(
    ctb_Stack_t const * const self
);

/**
 * @brief Clears the stack.
 *
 * @param self Pointer to the stack instance.
 */
void ctb_Stack_clear(
    ctb_Stack_t * const self
);

/** @} */
#endif // CTB_STACK_H
