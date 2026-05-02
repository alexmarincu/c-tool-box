#include "unity.h"

#include "ctb_Stack.h"

#include "ctb_SList.h"
#include "ctb_SListIterator.h"
#include "ctb_SNode.h"

void setUp(void) {}
void tearDown(void) {}

void test_ctb_Stack_init_should_initialize_stack(void) {
    ctb_Stack_t stack;
    ctb_Stack_init(&stack);
    TEST_ASSERT_TRUE(ctb_Stack_isEmpty(&stack));
    TEST_ASSERT_NULL(ctb_Stack_peek(&stack));
}

void test_ctb_Stack_push_should_add_node_to_top(void) {
    ctb_Stack_t stack;
    ctb_Stack_init(&stack);
    ctb_SNode_t node1, node2;
    ctb_SNode_init(&node1);
    ctb_SNode_init(&node2);

    ctb_Stack_push(&stack, &node1);
    TEST_ASSERT_FALSE(ctb_Stack_isEmpty(&stack));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_Stack_peek(&stack));

    ctb_Stack_push(&stack, &node2);
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_Stack_peek(&stack));
}

void test_ctb_Stack_pop_should_remove_node_from_top(void) {
    ctb_Stack_t stack;
    ctb_Stack_init(&stack);
    ctb_SNode_t node1, node2;
    ctb_SNode_init(&node1);
    ctb_SNode_init(&node2);

    ctb_Stack_push(&stack, &node1);
    ctb_Stack_push(&stack, &node2);

    TEST_ASSERT_EQUAL_PTR(&node2, ctb_Stack_pop(&stack));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_Stack_peek(&stack));

    TEST_ASSERT_EQUAL_PTR(&node1, ctb_Stack_pop(&stack));
    TEST_ASSERT_TRUE(ctb_Stack_isEmpty(&stack));
    TEST_ASSERT_NULL(ctb_Stack_pop(&stack));
}

void test_ctb_Stack_peek_should_return_top_node_without_removing(void) {
    ctb_Stack_t stack;
    ctb_Stack_init(&stack);
    ctb_SNode_t node1;
    ctb_SNode_init(&node1);

    ctb_Stack_push(&stack, &node1);
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_Stack_peek(&stack));
    TEST_ASSERT_FALSE(ctb_Stack_isEmpty(&stack));
}

void test_ctb_Stack_clear_should_empty_stack(void) {
    ctb_Stack_t stack;
    ctb_Stack_init(&stack);
    ctb_SNode_t node1, node2;
    ctb_SNode_init(&node1);
    ctb_SNode_init(&node2);

    ctb_Stack_push(&stack, &node1);
    ctb_Stack_push(&stack, &node2);

    ctb_Stack_clear(&stack);
    TEST_ASSERT_TRUE(ctb_Stack_isEmpty(&stack));
    TEST_ASSERT_NULL(ctb_Stack_peek(&stack));
}
