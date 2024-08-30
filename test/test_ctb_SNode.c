#include "ctb.h"
#include "ctb_SNode.h"
#include "unity.h"
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void test_ctb_SNode_init_should_set_next_to_null(void) {
    typedef struct
    {
        uint16_t    dummy;
        ctb_SNode_t node;
    } Obj_t;
    Obj_t obj;
    memset(&obj, 0xFF, sizeof(obj));
    ctb_SNode_init(&obj.node);
    TEST_ASSERT_TRUE(ctb_containerOf(&obj.node, Obj_t, node) == &obj);
    TEST_ASSERT_TRUE(ctb_SNode_getNext(&obj.node) == NULL);
}
