#include <string.h>

#include "unity.h"

#include "ctb_SList.h"
#include "ctb_SNode.h"

void setUp(void) {}
void tearDown(void) {}

void test_ctb_SList_init_should_initialize_list(void) {
    ctb_SList_t list;
    ctb_SList_init(&list);
    TEST_ASSERT_TRUE(ctb_SList_isEmpty(&list));
    TEST_ASSERT_EQUAL_INT(0, ctb_SList_getSize(&list));
    TEST_ASSERT_NULL(ctb_SList_getFirst(&list));
}

void test_ctb_SList_addFirst_should_add_node_to_front(void) {
    ctb_SList_t list;
    ctb_SList_init(&list);
    ctb_SNode_t node1, node2;
    ctb_SNode_init(&node1);
    ctb_SNode_init(&node2);

    ctb_SList_addFirst(&list, &node1);
    TEST_ASSERT_FALSE(ctb_SList_isEmpty(&list));
    TEST_ASSERT_EQUAL_INT(1, ctb_SList_getSize(&list));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_SList_getFirst(&list));

    ctb_SList_addFirst(&list, &node2);
    TEST_ASSERT_EQUAL_INT(2, ctb_SList_getSize(&list));
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_SList_getFirst(&list));
    TEST_ASSERT_EQUAL_PTR(&node1, node2.next);
}

void test_ctb_SList_addLast_should_add_node_to_back(void) {
    ctb_SList_t list;
    ctb_SList_init(&list);
    ctb_SNode_t node1, node2;
    ctb_SNode_init(&node1);
    ctb_SNode_init(&node2);

    ctb_SList_addLast(&list, &node1);
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_SList_getFirst(&list));

    ctb_SList_addLast(&list, &node2);
    TEST_ASSERT_EQUAL_INT(2, ctb_SList_getSize(&list));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_SList_getFirst(&list));
    TEST_ASSERT_EQUAL_PTR(&node2, node1.next);
    TEST_ASSERT_NULL(node2.next);
}

void test_ctb_SList_removeFirst_should_remove_from_front(void) {
    ctb_SList_t list;
    ctb_SList_init(&list);
    ctb_SNode_t node1, node2;
    ctb_SList_addLast(&list, &node1);
    ctb_SList_addLast(&list, &node2);

    TEST_ASSERT_EQUAL_PTR(&node1, ctb_SList_removeFirst(&list));
    TEST_ASSERT_EQUAL_INT(1, ctb_SList_getSize(&list));
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_SList_getFirst(&list));

    TEST_ASSERT_EQUAL_PTR(&node2, ctb_SList_removeFirst(&list));
    TEST_ASSERT_TRUE(ctb_SList_isEmpty(&list));
}

void test_ctb_SList_getIndexOf_should_return_correct_index(void) {
    ctb_SList_t list;
    ctb_SList_init(&list);
    ctb_SNode_t node1, node2, node3;
    ctb_SList_addLast(&list, &node1);
    ctb_SList_addLast(&list, &node2);

    TEST_ASSERT_EQUAL_INT(0, ctb_SList_getIndexOf(&list, &node1));
    TEST_ASSERT_EQUAL_INT(1, ctb_SList_getIndexOf(&list, &node2));
    TEST_ASSERT_EQUAL_INT(SIZE_MAX, ctb_SList_getIndexOf(&list, &node3));
}

void test_ctb_SList_addByIndex_should_add_at_index(void) {
    ctb_SList_t list;
    ctb_SList_init(&list);
    ctb_SNode_t node1, node2, node3;
    ctb_SList_addFirst(&list, &node1);
    ctb_SList_addLast(&list, &node3);

    ctb_SList_addByIndex(&list, &node2, 1);
    TEST_ASSERT_EQUAL_INT(3, ctb_SList_getSize(&list));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_SList_getByIndex(&list, 0));
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_SList_getByIndex(&list, 1));
    TEST_ASSERT_EQUAL_PTR(&node3, ctb_SList_getByIndex(&list, 2));
}

void test_ctb_SList_getLast_should_return_last_node(void) {
    ctb_SList_t list;
    ctb_SList_init(&list);
    TEST_ASSERT_NULL(ctb_SList_getLast(&list));

    ctb_SNode_t node1, node2;
    ctb_SList_addFirst(&list, &node1);
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_SList_getLast(&list));

    ctb_SList_addLast(&list, &node2);
    TEST_ASSERT_EQUAL_PTR(&node2, ctb_SList_getLast(&list));
}

void test_ctb_SList_removeByIndex_should_remove_at_index(void) {
    ctb_SList_t list;
    ctb_SList_init(&list);
    ctb_SNode_t node1, node2, node3;
    ctb_SList_addLast(&list, &node1);
    ctb_SList_addLast(&list, &node2);
    ctb_SList_addLast(&list, &node3);

    TEST_ASSERT_EQUAL_PTR(&node2, ctb_SList_removeByIndex(&list, 1));
    TEST_ASSERT_EQUAL_INT(2, ctb_SList_getSize(&list));
    TEST_ASSERT_EQUAL_PTR(&node3, node1.next);
}

void test_ctb_SList_removeLast_should_remove_from_back(void) {
    ctb_SList_t list;
    ctb_SList_init(&list);
    ctb_SNode_t node1, node2;
    ctb_SList_addLast(&list, &node1);
    ctb_SList_addLast(&list, &node2);

    TEST_ASSERT_EQUAL_PTR(&node2, ctb_SList_removeLast(&list));
    TEST_ASSERT_EQUAL_INT(1, ctb_SList_getSize(&list));
    TEST_ASSERT_EQUAL_PTR(&node1, ctb_SList_getFirst(&list));
    TEST_ASSERT_NULL(node1.next);
}

void test_ctb_SList_remove_should_remove_specific_node(void) {
    ctb_SList_t list;
    ctb_SList_init(&list);
    ctb_SNode_t node1, node2, node3;
    ctb_SList_addLast(&list, &node1);
    ctb_SList_addLast(&list, &node2);
    ctb_SList_addLast(&list, &node3);

    TEST_ASSERT_EQUAL_PTR(&node2, ctb_SList_remove(&list, &node2));
    TEST_ASSERT_EQUAL_INT(2, ctb_SList_getSize(&list));
    TEST_ASSERT_EQUAL_PTR(&node3, node1.next);

    TEST_ASSERT_EQUAL_PTR(&node1, ctb_SList_remove(&list, &node1));
    TEST_ASSERT_EQUAL_PTR(&node3, ctb_SList_getFirst(&list));

    TEST_ASSERT_NULL(ctb_SList_remove(&list, &node2)); // Already removed
}

void test_ctb_SList_clear_should_empty_list(void) {
    ctb_SList_t list;
    ctb_SList_init(&list);
    ctb_SNode_t node1, node2;
    ctb_SList_addLast(&list, &node1);
    ctb_SList_addLast(&list, &node2);

    ctb_SList_clear(&list);
    TEST_ASSERT_TRUE(ctb_SList_isEmpty(&list));
    TEST_ASSERT_EQUAL_INT(0, ctb_SList_getSize(&list));
    TEST_ASSERT_NULL(ctb_SList_getFirst(&list));
}
