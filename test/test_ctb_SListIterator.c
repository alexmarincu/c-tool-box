#include "unity.h"

#include "ctb_SListIterator.h"

#include "ctb_SList.h"
#include "ctb_SNode.h"

void setUp(void) {}
void tearDown(void) {}

void test_ctb_SListIterator_init_should_initialize_iterator(void) {
    ctb_SList_t         list;
    ctb_SListIterator_t iterator;
    ctb_SNode_t         node1;

    ctb_SList_init(&list);
    ctb_SNode_init(&node1);
    ctb_SList_addFirst(&list, &node1);

    ctb_SListIterator_init(&iterator, &list);

    TEST_ASSERT_EQUAL_PTR(&list, iterator.list);
    TEST_ASSERT_EQUAL_PTR(&node1, iterator.nextNode);
}

void test_ctb_SListIterator_resetToFirst_should_reset_to_first_node(void) {
    ctb_SList_t         list;
    ctb_SListIterator_t iterator;
    ctb_SNode_t         node1, node2;

    ctb_SList_init(&list);
    ctb_SNode_init(&node1);
    ctb_SNode_init(&node2);
    ctb_SList_addLast(&list, &node1);
    ctb_SList_addLast(&list, &node2);

    ctb_SListIterator_init(&iterator, &list);
    ctb_SListIterator_next(&iterator); // Move to node2
    TEST_ASSERT_EQUAL_PTR(&node2, iterator.nextNode);

    ctb_SListIterator_resetToFirst(&iterator);
    TEST_ASSERT_EQUAL_PTR(&node1, iterator.nextNode);
}

void test_ctb_SListIterator_hasNext_and_next_should_iterate_forward(void) {
    ctb_SList_t         list;
    ctb_SListIterator_t iterator;
    ctb_SNode_t         node1, node2;

    ctb_SList_init(&list);
    ctb_SNode_init(&node1);
    ctb_SNode_init(&node2);
    ctb_SList_addLast(&list, &node1);
    ctb_SList_addLast(&list, &node2);

    ctb_SListIterator_init(&iterator, &list);

    TEST_ASSERT_TRUE(ctb_SListIterator_hasNext(&iterator));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_SListIterator_next(&iterator));

    TEST_ASSERT_TRUE(ctb_SListIterator_hasNext(&iterator));
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_SListIterator_next(&iterator));

    TEST_ASSERT_FALSE(ctb_SListIterator_hasNext(&iterator));
    TEST_ASSERT_NULL(ctb_SListIterator_next(&iterator));
}

static int callCount = 0;

static void countOperation(
    ctb_SNode_t * const node
) {
    (void)node;
    callCount++;
}

void test_ctb_SListIterator_forEach_should_apply_to_all_nodes(void) {
    ctb_SList_t         list;
    ctb_SListIterator_t iterator;
    ctb_SNode_t         node1, node2, node3;

    ctb_SList_init(&list);
    ctb_SNode_init(&node1);
    ctb_SNode_init(&node2);
    ctb_SNode_init(&node3);
    ctb_SList_addLast(&list, &node1);
    ctb_SList_addLast(&list, &node2);
    ctb_SList_addLast(&list, &node3);

    ctb_SListIterator_init(&iterator, &list);
    callCount = 0;
    ctb_SListIterator_forEach(&iterator, countOperation);

    TEST_ASSERT_EQUAL_INT(3, callCount);
}

static ctb_SNode_t * targetNode = NULL;

static bool findPredicate(
    ctb_SNode_t * const node
) {
    (void)node;
    return node == targetNode;
}

void test_ctb_SListIterator_find_should_return_matching_node(void) {
    ctb_SList_t         list;
    ctb_SListIterator_t iterator;
    ctb_SNode_t         node1, node2, node3;

    ctb_SList_init(&list);
    ctb_SNode_init(&node1);
    ctb_SNode_init(&node2);
    ctb_SNode_init(&node3);
    ctb_SList_addLast(&list, &node1);
    ctb_SList_addLast(&list, &node2);
    ctb_SList_addLast(&list, &node3);

    ctb_SListIterator_init(&iterator, &list);
    targetNode = &node2;
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_SListIterator_find(&iterator, findPredicate));

    ctb_SListIterator_resetToFirst(&iterator);
    targetNode = NULL; // Won't match anything
    TEST_ASSERT_NULL(ctb_SListIterator_find(&iterator, findPredicate));
}
