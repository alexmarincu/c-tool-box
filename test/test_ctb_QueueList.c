/**
 * @defgroup test_ctb_QueueList test_ctb_QueueList
 * @ingroup test
 * @{
 * @file
 */
#include "unity.h"

#include "ctb_QueueList.h"

#include "ctb_DList.h"
#include "ctb_DListIterator.h"
#include "ctb_DNode.h"

void setUp(void) {}
void tearDown(void) {}

void test_ctb_QueueList_init_should_initialize_queue(void) {
    ctb_QueueList_t queue;
    ctb_QueueList_init(&queue);
    TEST_ASSERT_TRUE(ctb_QueueList_isEmpty(&queue));
}

void test_ctb_QueueList_enqueue_should_add_node_to_queue(void) {
    ctb_QueueList_t queue;
    ctb_QueueList_init(&queue);
    ctb_DNode_t node1, node2;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);

    ctb_QueueList_enqueue(&queue, &node1);
    TEST_ASSERT_FALSE(ctb_QueueList_isEmpty(&queue));

    ctb_QueueList_enqueue(&queue, &node2);
    TEST_ASSERT_FALSE(ctb_QueueList_isEmpty(&queue));
}

void test_ctb_QueueList_dequeue_should_remove_node_from_queue_in_FIFO_order(void) {
    ctb_QueueList_t queue;
    ctb_QueueList_init(&queue);
    ctb_DNode_t node1, node2;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);

    ctb_QueueList_enqueue(&queue, &node1);
    ctb_QueueList_enqueue(&queue, &node2);

    TEST_ASSERT_EQUAL_PTR(&node1, ctb_QueueList_dequeue(&queue));
    TEST_ASSERT_FALSE(ctb_QueueList_isEmpty(&queue));

    TEST_ASSERT_EQUAL_PTR(&node2, ctb_QueueList_dequeue(&queue));
    TEST_ASSERT_TRUE(ctb_QueueList_isEmpty(&queue));

    TEST_ASSERT_NULL(ctb_QueueList_dequeue(&queue));
}

void test_ctb_QueueList_clear_should_empty_queue(void) {
    ctb_QueueList_t queue;
    ctb_QueueList_init(&queue);
    ctb_DNode_t node1, node2;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);

    ctb_QueueList_enqueue(&queue, &node1);
    ctb_QueueList_enqueue(&queue, &node2);

    ctb_QueueList_clear(&queue);
    TEST_ASSERT_TRUE(ctb_QueueList_isEmpty(&queue));
    TEST_ASSERT_NULL(ctb_QueueList_dequeue(&queue));
}

/** @} */
