/**
 * @defgroup test_ctb_StackList test_ctb_StackList
 * @ingroup test
 * @{
 * @file
 */
#include "unity.h"

#include "ctb_StackList.h"

#include "ctb_SList.h"
#include "ctb_SListIterator.h"
#include "ctb_SNode.h"

void setUp(void) {}
void tearDown(void) {}

void test_ctb_StackList_init_should_initialize_stack(void) {
    ctb_StackList_t stack;
    ctb_StackList_init(&stack);
    TEST_ASSERT_TRUE(ctb_StackList_isEmpty(&stack));
    TEST_ASSERT_NULL(ctb_StackList_peek(&stack));
}

void test_ctb_StackList_push_should_add_node_to_top(void) {
    ctb_StackList_t stack;
    ctb_StackList_init(&stack);
    ctb_SNode_t node1, node2;
    ctb_SNode_init(&node1);
    ctb_SNode_init(&node2);

    ctb_StackList_push(&stack, &node1);
    TEST_ASSERT_FALSE(ctb_StackList_isEmpty(&stack));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_StackList_peek(&stack));

    ctb_StackList_push(&stack, &node2);
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_StackList_peek(&stack));
}

void test_ctb_StackList_pop_should_remove_node_from_top(void) {
    ctb_StackList_t stack;
    ctb_StackList_init(&stack);
    ctb_SNode_t node1, node2;
    ctb_SNode_init(&node1);
    ctb_SNode_init(&node2);

    ctb_StackList_push(&stack, &node1);
    ctb_StackList_push(&stack, &node2);

    TEST_ASSERT_EQUAL_PTR(&node2, ctb_StackList_pop(&stack));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_StackList_peek(&stack));

    TEST_ASSERT_EQUAL_PTR(&node1, ctb_StackList_pop(&stack));
    TEST_ASSERT_TRUE(ctb_StackList_isEmpty(&stack));
    TEST_ASSERT_NULL(ctb_StackList_pop(&stack));
}

void test_ctb_StackList_peek_should_return_top_node_without_removing(void) {
    ctb_StackList_t stack;
    ctb_StackList_init(&stack);
    ctb_SNode_t node1;
    ctb_SNode_init(&node1);

    ctb_StackList_push(&stack, &node1);
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_StackList_peek(&stack));
    TEST_ASSERT_FALSE(ctb_StackList_isEmpty(&stack));
}

void test_ctb_StackList_clear_should_empty_stack(void) {
    ctb_StackList_t stack;
    ctb_StackList_init(&stack);
    ctb_SNode_t node1, node2;
    ctb_SNode_init(&node1);
    ctb_SNode_init(&node2);

    ctb_StackList_push(&stack, &node1);
    ctb_StackList_push(&stack, &node2);

    ctb_StackList_clear(&stack);
    TEST_ASSERT_TRUE(ctb_StackList_isEmpty(&stack));
    TEST_ASSERT_NULL(ctb_StackList_peek(&stack));
}

/** @} */
