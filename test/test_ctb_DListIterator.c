#include "unity.h"

#include "ctb_DListIterator.h"

#include "ctb_DList.h"
#include "ctb_DNode.h"

void setUp(void) {}
void tearDown(void) {}

void test_ctb_DListIterator_init_should_initialize_iterator(void) {
    ctb_DList_t         list;
    ctb_DListIterator_t iterator;
    ctb_DNode_t         node1;

    ctb_DList_init(&list);
    ctb_DNode_init(&node1);
    ctb_DList_addFirst(&list, &node1);

    ctb_DListIterator_init(&iterator, &list);

    TEST_ASSERT_EQUAL_PTR(&list, iterator.list);
    TEST_ASSERT_EQUAL_PTR(&node1, iterator.current);
}

void test_ctb_DListIterator_resetToFirst_should_reset_to_first_node(void) {
    ctb_DList_t         list;
    ctb_DListIterator_t iterator;
    ctb_DNode_t         node1, node2;

    ctb_DList_init(&list);
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);

    ctb_DListIterator_init(&iterator, &list);
    ctb_DListIterator_next(&iterator); // Move to node2
    TEST_ASSERT_EQUAL_PTR(&node2, iterator.current);

    ctb_DListIterator_resetToFirst(&iterator);
    TEST_ASSERT_EQUAL_PTR(&node1, iterator.current);
}

void test_ctb_DListIterator_resetToLast_should_reset_to_last_node(void) {
    ctb_DList_t         list;
    ctb_DListIterator_t iterator;
    ctb_DNode_t         node1, node2;

    ctb_DList_init(&list);
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);

    ctb_DListIterator_init(&iterator, &list);
    TEST_ASSERT_EQUAL_PTR(&node1, iterator.current);

    ctb_DListIterator_resetToLast(&iterator);
    TEST_ASSERT_EQUAL_PTR(&node2, iterator.current);
}

void test_ctb_DListIterator_hasNext_and_next_should_iterate_forward(void) {
    ctb_DList_t         list;
    ctb_DListIterator_t iterator;
    ctb_DNode_t         node1, node2;

    ctb_DList_init(&list);
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);

    ctb_DListIterator_init(&iterator, &list);

    TEST_ASSERT_TRUE(ctb_DListIterator_hasNext(&iterator));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DListIterator_next(&iterator));

    TEST_ASSERT_TRUE(ctb_DListIterator_hasNext(&iterator));
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_DListIterator_next(&iterator));

    TEST_ASSERT_FALSE(ctb_DListIterator_hasNext(&iterator));
    TEST_ASSERT_NULL(ctb_DListIterator_next(&iterator));
}

void test_ctb_DListIterator_hasPrevious_and_previous_should_iterate_backward(void) {
    ctb_DList_t         list;
    ctb_DListIterator_t iterator;
    ctb_DNode_t         node1, node2;

    ctb_DList_init(&list);
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);

    ctb_DListIterator_init(&iterator, &list);
    ctb_DListIterator_resetToLast(&iterator);

    TEST_ASSERT_TRUE(ctb_DListIterator_hasPrevious(&iterator));
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_DListIterator_previous(&iterator));

    TEST_ASSERT_TRUE(ctb_DListIterator_hasPrevious(&iterator));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DListIterator_previous(&iterator));

    TEST_ASSERT_FALSE(ctb_DListIterator_hasPrevious(&iterator));
    TEST_ASSERT_NULL(ctb_DListIterator_previous(&iterator));
}

static int callCount = 0;

static void countOperation(
    ctb_DNode_t * const node
) {
    (void)node;
    callCount++;
}

void test_ctb_DListIterator_forEach_should_apply_to_all_nodes(void) {
    ctb_DList_t         list;
    ctb_DListIterator_t iterator;
    ctb_DNode_t         node1, node2, node3;

    ctb_DList_init(&list);
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
    ctb_DNode_init(&node3);
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);
    ctb_DList_addLast(&list, &node3);

    ctb_DListIterator_init(&iterator, &list);
    callCount = 0;
    ctb_DListIterator_forEach(&iterator, countOperation);

    TEST_ASSERT_EQUAL_INT(3, callCount);
}

static ctb_DNode_t * targetNode = NULL;

static bool findPredicate(
    ctb_DNode_t * const node
) {
    (void)node;
    return node == targetNode;
}

void test_ctb_DListIterator_find_should_return_matching_node(void) {
    ctb_DList_t         list;
    ctb_DListIterator_t iterator;
    ctb_DNode_t         node1, node2, node3;

    ctb_DList_init(&list);
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
    ctb_DNode_init(&node3);
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);
    ctb_DList_addLast(&list, &node3);

    ctb_DListIterator_init(&iterator, &list);
    targetNode = &node2;
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_DListIterator_find(&iterator, findPredicate));

    ctb_DListIterator_resetToFirst(&iterator);
    targetNode = NULL; // Won't match anything
    TEST_ASSERT_NULL(ctb_DListIterator_find(&iterator, findPredicate));
}
