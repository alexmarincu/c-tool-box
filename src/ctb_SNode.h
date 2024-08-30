/**
 * @file
 */
#ifndef CTB_SNODE_H
#define CTB_SNODE_H

/**
 * @brief Singly linked node type
 */
typedef struct ctb_SNode ctb_SNode_t;

/**
 * @brief Singly linked node data structure
 */
struct ctb_SNode {
    ctb_SNode_t * next; /**< Pointer to the next node */
};

/**
 * @brief Initializes a singly linked node
 *
 * @param self Pointer to a singly linked node
 * @return Pointer to the initialized singly linked node
 */
ctb_SNode_t * ctb_SNode_init(ctb_SNode_t * const self);

/**
 * @brief Returns the next node
 *
 * @param self Pointer to a singly linked node
 * @return Pointer to the next node
 */
ctb_SNode_t * ctb_SNode_getNext(ctb_SNode_t * const self);

#endif // CTB_SNODE_H
