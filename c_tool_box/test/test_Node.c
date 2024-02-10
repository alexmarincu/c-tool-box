#include "ctb_Node.h"
#include "unity.h"
#include <stddef.h>

TEST_SOURCE_FILE("ctb_Node.c")

void setUp(void) {}
void tearDown(void) {}

void test_Node_init_should_set_next_and_prev_to_null(void) {
    ctb_Node node = { .next = (ctb_Node *)1, .prev = (ctb_Node *)2 };
    ctb_Node_init(&node);
    TEST_ASSERT_TRUE(node.next == NULL);
    TEST_ASSERT_TRUE(node.prev == NULL);
}
