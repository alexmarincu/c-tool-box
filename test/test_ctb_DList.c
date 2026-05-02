#include "unity.h"

#include "ctb_DList.h"

#include "ctb_DListIterator.h"
#include "ctb_DNode.h"

void setUp(void) {}
void tearDown(void) {}

void test_ctb_DList_init_should_initialize_list(void) {
    ctb_DList_t list;
    ctb_DList_init(&list);
    TEST_ASSERT_TRUE(ctb_DList_isEmpty(&list));
    TEST_ASSERT_EQUAL_INT(0, ctb_DList_getSize(&list));
    TEST_ASSERT_NULL(ctb_DList_getFirst(&list));
    TEST_ASSERT_NULL(ctb_DList_getLast(&list));
}

void test_ctb_DList_isEmpty_should_return_true_for_empty_list(void) {
    ctb_DList_t list;
    ctb_DList_init(&list);
    TEST_ASSERT_TRUE(ctb_DList_isEmpty(&list));
}

void test_ctb_DList_isEmpty_should_return_false_for_non_empty_list(void) {
    ctb_DList_t list;
    ctb_DList_init(&list);
    ctb_DNode_t node1;
    ctb_DNode_init(&node1);

    ctb_DList_addFirst(&list, &node1);
    TEST_ASSERT_FALSE(ctb_DList_isEmpty(&list));
}

void test_ctb_DList_getSize_should_return_correct_size(void) {
    ctb_DList_t list;
    ctb_DList_init(&list);
    TEST_ASSERT_EQUAL_INT(0, ctb_DList_getSize(&list));

    ctb_DNode_t node1, node2;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);

    ctb_DList_addFirst(&list, &node1);
    TEST_ASSERT_EQUAL_INT(1, ctb_DList_getSize(&list));

    ctb_DList_addLast(&list, &node2);
    TEST_ASSERT_EQUAL_INT(2, ctb_DList_getSize(&list));
}

void test_ctb_DList_addFirst_should_add_node_to_front(void) {
    ctb_DList_t list;
    ctb_DList_init(&list);
    ctb_DNode_t node1, node2;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);

    ctb_DList_addFirst(&list, &node1);
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getFirst(&list));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getLast(&list));

    ctb_DList_addFirst(&list, &node2);
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_DList_getFirst(&list));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getLast(&list));
    TEST_ASSERT_EQUAL_PTR(&node1, node2.next);
    TEST_ASSERT_EQUAL_PTR(&node2, node1.prev);
}

void test_ctb_DList_addLast_should_add_node_to_back(void) {
    ctb_DList_t list;
    ctb_DList_init(&list);
    ctb_DNode_t node1, node2;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);

    ctb_DList_addLast(&list, &node1);
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getFirst(&list));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getLast(&list));

    ctb_DList_addLast(&list, &node2);
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_DList_getFirst(&list));
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_DList_getLast(&list));
    TEST_ASSERT_EQUAL_PTR(&node2, node1.next);
    TEST_ASSERT_EQUAL_PTR(&node1, node2.prev);
}

void test_ctb_DList_addByIndex_should_add_at_index(void) {
    ctb_DList_t list;
    ctb_DList_init(&list);
    ctb_DNode_t node1, node2, node3;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
    ctb_DNode_init(&node3);

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

void test_ctb_DList_removeFirst_should_remove_from_front(void) {
    ctb_DList_t list;
    ctb_DList_init(&list);
    ctb_DNode_t node1, node2;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
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

void test_ctb_DList_removeLast_should_remove_from_back(void) {
    ctb_DList_t list;
    ctb_DList_init(&list);
    ctb_DNode_t node1, node2;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
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

void test_ctb_DList_removeByIndex_should_remove_at_index(void) {
    ctb_DList_t list;
    ctb_DList_init(&list);
    ctb_DNode_t node1, node2, node3;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
    ctb_DNode_init(&node3);
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

void test_ctb_DList_remove_should_remove_specific_node(void) {
    ctb_DList_t list;
    ctb_DList_init(&list);
    ctb_DNode_t node1, node2, node3;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
    ctb_DNode_init(&node3);
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

void test_ctb_DList_getIndexOf_should_return_correct_index(void) {
    ctb_DList_t list;
    ctb_DList_init(&list);
    ctb_DNode_t node1, node2, node3;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
    ctb_DNode_init(&node3);
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);

    TEST_ASSERT_EQUAL_INT(0, ctb_DList_getIndexOf(&list, &node1));
    TEST_ASSERT_EQUAL_INT(1, ctb_DList_getIndexOf(&list, &node2));
    TEST_ASSERT_EQUAL_INT(SIZE_MAX, ctb_DList_getIndexOf(&list, &node3));
}

static size_t callCount = 0;

static void countOperation(
    ctb_DNode_t * const node
) {
    (void)node;
    callCount++;
}

void test_ctb_DList_forEach_should_apply_operation_to_all_nodes(void) {
    ctb_DList_t list;
    ctb_DList_init(&list);
    ctb_DNode_t node1, node2, node3;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
    ctb_DNode_init(&node3);
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);
    ctb_DList_addLast(&list, &node3);

    callCount = 0;
    ctb_DList_forEach(&list, countOperation);
    TEST_ASSERT_EQUAL_INT(3, callCount);
}

static ctb_DNode_t * findTarget = NULL;

static bool findPredicate(
    ctb_DNode_t * const node
) {
    (void)node;
    return node == findTarget;
}

void test_ctb_DList_find_should_return_first_matching_node(void) {
    ctb_DList_t list;
    ctb_DList_init(&list);
    ctb_DNode_t node1, node2, node3;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
    ctb_DNode_init(&node3);
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);
    ctb_DList_addLast(&list, &node3);

    findTarget = &node2;
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_DList_find(&list, findPredicate));

    ctb_DList_remove(&list, &node2);
    TEST_ASSERT_NULL(ctb_DList_find(&list, findPredicate));
}

void test_ctb_DList_clear_should_empty_list(void) {
    ctb_DList_t list;
    ctb_DList_init(&list);
    ctb_DNode_t node1, node2;
    ctb_DNode_init(&node1);
    ctb_DNode_init(&node2);
    ctb_DList_addLast(&list, &node1);
    ctb_DList_addLast(&list, &node2);

    ctb_DList_clear(&list);
    TEST_ASSERT_TRUE(ctb_DList_isEmpty(&list));
    TEST_ASSERT_NULL(ctb_DList_getFirst(&list));
    TEST_ASSERT_NULL(ctb_DList_getLast(&list));
}
