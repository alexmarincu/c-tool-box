/*----------------------------------------------------------------------------*/
#ifndef CTB_NODE_H
#define CTB_NODE_H
/*----------------------------------------------------------------------------*/
typedef struct ctb_Node ctb_Node;
/*----------------------------------------------------------------------------*/
struct ctb_Node {
    ctb_Node * next;
    ctb_Node * prev;
};
/*----------------------------------------------------------------------------*/
ctb_Node * ctb_Node_init(ctb_Node * const self);
#endif // CTB_NODE_H
