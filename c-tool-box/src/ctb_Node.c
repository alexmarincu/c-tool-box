/*----------------------------------------------------------------------------*/
#include "ctb_Node.h"
/*----------------------------------------------------------------------------*/
#include <stddef.h>
/*----------------------------------------------------------------------------*/
// cppcheck-suppress unusedFunction // API function
ctb_Node * ctb_Node_init(ctb_Node * const self) {
    self->next = NULL;
    self->prev = NULL;
    return self;
}
