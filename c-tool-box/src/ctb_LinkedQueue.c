/*----------------------------------------------------------------------------*/
#include "ctb_LinkedQueue.h"
/*----------------------------------------------------------------------------*/
// cppcheck-suppress unusedFunction // API function
ctb_LinkedQueue * ctb_LinkedQueue_init(ctb_LinkedQueue * const self) {
    ctb_LinkedList_init(&self->_linkedList);
    return self;
}
/*----------------------------------------------------------------------------*/
// cppcheck-suppress unusedFunction // API function
bool ctb_LinkedQueue_isEmpty(ctb_LinkedQueue * const self) {
    return ctb_LinkedList_isEmpty(&self->_linkedList);
}
/*----------------------------------------------------------------------------*/
// cppcheck-suppress unusedFunction // API function
void ctb_LinkedQueue_enqueue(
    ctb_LinkedQueue * const self, ctb_Node * const node
) {
    ctb_LinkedList_addLast(&self->_linkedList, node);
}
/*----------------------------------------------------------------------------*/
// cppcheck-suppress unusedFunction // API function
ctb_Node * ctb_LinkedQueue_dequeue(ctb_LinkedQueue * const self) {
    return ctb_LinkedList_removeFirst(&self->_linkedList);
}
/*----------------------------------------------------------------------------*/
// cppcheck-suppress unusedFunction // API function
void ctb_LinkedQueue_clear(ctb_LinkedQueue * const self) {
    ctb_LinkedList_clear(&self->_linkedList);
}
