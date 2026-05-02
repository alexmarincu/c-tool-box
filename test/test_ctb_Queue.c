#include "unity.h"

#include "ctb_Queue.h"

#include "ctb_DList.h"
#include "ctb_DListIterator.h"
#include "ctb_DNode.h"

void setUp(void) {}
void tearDown(void) {}

void test_ctb_Queue_init_should_initialize_queue(void) {
    ctb_Queue_t queue;
    ctb_Queue_init(&queue);
    TEST_ASSERT_TRUE(ctb_Queue_isEmpty(&queue));
}

void test_ctb_Queue_enqueue_should_add_node_to_queue(void) {
    ctb_Queue_t queue;
    ctb_Queue_init(&queue);
    ctb_DNode_t node1, node2;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);

    ctb_Queue_enqueue(&queue, &node1);
    TEST_ASSERT_FALSE(ctb_Queue_isEmpty(&queue));

    ctb_Queue_enqueue(&queue, &node2);
    TEST_ASSERT_FALSE(ctb_Queue_isEmpty(&queue));
}

void test_ctb_Queue_dequeue_should_remove_node_from_queue_in_FIFO_order(void) {
    ctb_Queue_t queue;
    ctb_Queue_init(&queue);
    ctb_DNode_t node1, node2;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);

    ctb_Queue_enqueue(&queue, &node1);
    ctb_Queue_enqueue(&queue, &node2);

    TEST_ASSERT_EQUAL_PTR(&node1, ctb_Queue_dequeue(&queue));
    TEST_ASSERT_FALSE(ctb_Queue_isEmpty(&queue));

    TEST_ASSERT_EQUAL_PTR(&node2, ctb_Queue_dequeue(&queue));
    TEST_ASSERT_TRUE(ctb_Queue_isEmpty(&queue));

    TEST_ASSERT_NULL(ctb_Queue_dequeue(&queue));
}

void test_ctb_Queue_clear_should_empty_queue(void) {
    ctb_Queue_t queue;
    ctb_Queue_init(&queue);
    ctb_DNode_t node1, node2;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);

    ctb_Queue_enqueue(&queue, &node1);
    ctb_Queue_enqueue(&queue, &node2);

    ctb_Queue_clear(&queue);
    TEST_ASSERT_TRUE(ctb_Queue_isEmpty(&queue));
    TEST_ASSERT_NULL(ctb_Queue_dequeue(&queue));
}
