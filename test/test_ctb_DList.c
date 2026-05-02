#include "unity.h"

#include "ctb_DList.h"
#include "ctb_DListIterator.h"
#include "ctb_DNode.h"

static ctb_DList_t list;
static ctb_DNode_t node1;
static ctb_DNode_t node2;
static ctb_DNode_t node3;

void setUp(void) {
    ctb_DList_init(&list);
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
    ctb_DNode_init(&node3);
}

void tearDown(void) {}

void test_ctb_DList_init_should_initializeEmptyList(void) {
    ctb_DList_t   newList;
    ctb_DList_t * result = ctb_DList_init(&newList);

    TEST_ASSERT_EQUAL_PTR(&newList, result);
    TEST_ASSERT_NULL(newList.first);
    TEST_ASSERT_NULL(newList.last);
    TEST_ASSERT_EQUAL_INT(0, newList.size);
}

void test_ctb_DList_isEmpty_should_returnTrueForEmptyList(void) {
    TEST_ASSERT_TRUE(ctb_DList_isEmpty(&list));
}

void test_ctb_DList_isEmpty_should_returnFalseForNonEmptyList(void) {
    ctb_DList_addFirst(&list, &node1);
    TEST_ASSERT_FALSE(ctb_DList_isEmpty(&list));
}

void test_ctb_DList_getSize_should_returnCorrectSize(void) {
    TEST_ASSERT_EQUAL_INT(0, ctb_DList_getSize(&list));

    ctb_DList_addFirst(&list, &node1);
    TEST_ASSERT_EQUAL_INT(1, ctb_DList_getSize(&list));

    ctb_DList_addLast(&list, &node2);
    TEST_ASSERT_EQUAL_INT(2, ctb_DList_getSize(&list));
}

void test_ctb_DList_addFirst_should_addNodeToBeginning(void) {
    ctb_DList_addFirst(&list, &node1);
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getFirst(&list));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getLast(&list));

    ctb_DList_addFirst(&list, &node2);
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_DList_getFirst(&list));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getLast(&list));
    TEST_ASSERT_EQUAL_PTR(&node1, node2.next);
    TEST_ASSERT_EQUAL_PTR(&node2, node1.prev);
}

void test_ctb_DList_addLast_should_addNodeToEnd(void) {
    ctb_DList_addLast(&list, &node1);
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getFirst(&list));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getLast(&list));

    ctb_DList_addLast(&list, &node2);
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getFirst(&list));
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_DList_getLast(&list));
    TEST_ASSERT_EQUAL_PTR(&node2, node1.next);
    TEST_ASSERT_EQUAL_PTR(&node1, node2.prev);
}

void test_ctb_DList_addByIndex_should_addNodeAtCorrectIndex(void) {
    // Add to empty list
    ctb_DList_addByIndex(&list, &node1, 0);
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getFirst(&list));

    // Add at index 0 (beginning)
    ctb_DList_addByIndex(&list, &node2, 0);
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_DList_getFirst(&list));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getLast(&list));

    // Add at index size (end)
    ctb_DList_addByIndex(&list, &node3, 2);
    TEST_ASSERT_EQUAL_PTR(&node3, ctb_DList_getLast(&list));

    // Add in middle
    ctb_DList_clear(&list);
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node3);
    ctb_DList_addByIndex(&list, &node2, 1);

    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getByIndex(&list, 0));
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_DList_getByIndex(&list, 1));
    TEST_ASSERT_EQUAL_PTR(&node3, ctb_DList_getByIndex(&list, 2));
}

void test_ctb_DList_removeFirst_should_removeAndReturnFirstNode(void) {
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);

    ctb_DNode_t * removed = ctb_DList_removeFirst(&list);
    TEST_ASSERT_EQUAL_PTR(&node1, removed);
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_DList_getFirst(&list));
    TEST_ASSERT_EQUAL_INT(1, ctb_DList_getSize(&list));
    TEST_ASSERT_NULL(node2.prev);

    removed = ctb_DList_removeFirst(&list);
    TEST_ASSERT_EQUAL_PTR(&node2, removed);
    TEST_ASSERT_TRUE(ctb_DList_isEmpty(&list));
}

void test_ctb_DList_removeLast_should_removeAndReturnLastNode(void) {
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);

    ctb_DNode_t * removed = ctb_DList_removeLast(&list);
    TEST_ASSERT_EQUAL_PTR(&node2, removed);
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getLast(&list));
    TEST_ASSERT_EQUAL_INT(1, ctb_DList_getSize(&list));
    TEST_ASSERT_NULL(node1.next);

    removed = ctb_DList_removeLast(&list);
    TEST_ASSERT_EQUAL_PTR(&node1, removed);
    TEST_ASSERT_TRUE(ctb_DList_isEmpty(&list));
}

void test_ctb_DList_removeByIndex_should_removeNodeAtCorrectIndex(void) {
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);
    ctb_DList_addLast(&list, &node3);

    // Remove middle
    ctb_DNode_t * removed = ctb_DList_removeByIndex(&list, 1);
    TEST_ASSERT_EQUAL_PTR(&node2, removed);
    TEST_ASSERT_EQUAL_INT(2, ctb_DList_getSize(&list));
    TEST_ASSERT_EQUAL_PTR(&node3, node1.next);
    TEST_ASSERT_EQUAL_PTR(&node1, node3.prev);

    // Remove first
    removed = ctb_DList_removeByIndex(&list, 0);
    TEST_ASSERT_EQUAL_PTR(&node1, removed);
    TEST_ASSERT_EQUAL_PTR(&node3, ctb_DList_getFirst(&list));

    // Remove last
    removed = ctb_DList_removeByIndex(&list, 0);
    TEST_ASSERT_EQUAL_PTR(&node3, removed);
    TEST_ASSERT_TRUE(ctb_DList_isEmpty(&list));
}

void test_ctb_DList_remove_should_removeSpecificNode(void) {
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);
    ctb_DList_addLast(&list, &node3);

    // Remove from middle
    ctb_DNode_t * removed = ctb_DList_remove(&list, &node2);
    TEST_ASSERT_EQUAL_PTR(&node2, removed);
    TEST_ASSERT_EQUAL_INT(2, ctb_DList_getSize(&list));
    TEST_ASSERT_EQUAL_PTR(&node3, node1.next);
    TEST_ASSERT_EQUAL_PTR(&node1, node3.prev);
}

void test_ctb_DList_getIndexOf_should_returnCorrectIndex(void) {
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);

    TEST_ASSERT_EQUAL_INT(0, ctb_DList_getIndexOf(&list, &node1));
    TEST_ASSERT_EQUAL_INT(1, ctb_DList_getIndexOf(&list, &node2));
    TEST_ASSERT_EQUAL_INT(SIZE_MAX, ctb_DList_getIndexOf(&list, &node3));
}

static size_t callCount = 0;
static void   countOperation(ctb_DNode_t * const node) {
    (void)node;
    callCount++;
}

void test_ctb_DList_forEach_should_applyOperationToAllNodes(void) {
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);
    ctb_DList_addLast(&list, &node3);

    callCount = 0;
    ctb_DList_forEach(&list, countOperation);
    TEST_ASSERT_EQUAL_INT(3, callCount);
}

static bool isNode2(ctb_DNode_t * const node) {
    (void)node;
    return node == &node2;
}

void test_ctb_DList_find_should_returnFirstMatchingNode(void) {
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);
    ctb_DList_addLast(&list, &node3);

    TEST_ASSERT_EQUAL_PTR(&node2, ctb_DList_find(&list, isNode2));

    ctb_DList_remove(&list, &node2);
    TEST_ASSERT_NULL(ctb_DList_find(&list, isNode2));
}

void test_ctb_DList_clear_should_removeAllNodes(void) {
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);
    ctb_DList_clear(&list);
    TEST_ASSERT_TRUE(ctb_DList_isEmpty(&list));
    TEST_ASSERT_NULL(ctb_DList_getFirst(&list));
    TEST_ASSERT_NULL(ctb_DList_getLast(&list));
}
