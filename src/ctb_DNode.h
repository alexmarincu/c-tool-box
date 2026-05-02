/**
 * @file
 */
#ifndef CTB_DNODE_H
#define CTB_DNODE_H
/**
 * @ingroup ctb
 * @defgroup ctb_DNode ctb_DNode
 * @{
 */

/**
 * @brief Doubly linked node type.
 */
typedef struct ctb_DNode ctb_DNode_t;

/**
 * @brief Doubly linked node data structure.
 */
struct ctb_DNode {
    ctb_DNode_t * next; /**< Pointer to the next node in the list. */
    ctb_DNode_t * prev; /**< Pointer to the previous node in the list. */
};

/**
 * @brief Initializes a doubly linked node.
 *
 * @param self Pointer to the doubly linked node to initialize.
 * @return Pointer to the initialized doubly linked node (self).
 */
ctb_DNode_t * ctb_DNode_init(
    ctb_DNode_t * const self
);

/**
 * @brief Returns the next node.
 *
 * @param self Pointer to the doubly linked node.
 * @return Pointer to the next node, or NULL if there is no next node.
 */
ctb_DNode_t * ctb_DNode_getNext(
    ctb_DNode_t const * const self
);

/**
 * @brief Returns the previous node.
 *
 * @param self Pointer to the doubly linked node.
 * @return Pointer to the previous node, or NULL if there is no previous node.
 */
ctb_DNode_t * ctb_DNode_getPrev(
    ctb_DNode_t const * const self
);

/** @} */
#endif // CTB_DNODE_H
