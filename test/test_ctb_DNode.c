#include "ctb.h"
#include "ctb_DNode.h"
#include "unity.h"
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void test_ctb_DNode_init_should_set_next_and_prev_to_null(void) {
    typedef struct
    {
        uint16_t    dummy;
        ctb_DNode_t node;
    } Obj_t;
    Obj_t obj;
    memset(&obj, 0xFF, sizeof(obj));
    ctb_DNode_init(&obj.node);
    TEST_ASSERT_TRUE(ctb_containerOf(&obj.node, Obj_t, node) == &obj);
    TEST_ASSERT_TRUE(ctb_DNode_getNext(&obj.node) == NULL);
    TEST_ASSERT_TRUE(ctb_DNode_getPrev(&obj.node) == NULL);
}
