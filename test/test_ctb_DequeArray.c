#include "unity.h"

#include "ctb_DequeArray.h"

void setUp(void) {}
void tearDown(void) {}

void test_ctb_DequeArray_init_should_initialize_deque(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));
    TEST_ASSERT_NOT_NULL(deque);
    TEST_ASSERT_TRUE(ctb_DequeArray_isEmpty(deque));
    TEST_ASSERT_EQUAL_UINT(0, ctb_DequeArray_getLength(deque));
    TEST_ASSERT_EQUAL_UINT(4, ctb_DequeArray_getCapacity(deque));
    TEST_ASSERT_NULL(ctb_DequeArray_peekFirst(deque));
    TEST_ASSERT_NULL(ctb_DequeArray_peekLast(deque));
}

void test_ctb_DequeArray_pushFirst_should_add_element_at_front(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int    val    = 42;
    void * result = ctb_DequeArray_pushFirst(deque, &val);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_INT(42, *(int *)result);
    TEST_ASSERT_EQUAL_INT(42, *(int *)ctb_DequeArray_peekFirst(deque));
    TEST_ASSERT_EQUAL_INT(42, *(int *)ctb_DequeArray_peekLast(deque));
    TEST_ASSERT_FALSE(ctb_DequeArray_isEmpty(deque));
    TEST_ASSERT_EQUAL_UINT(1, ctb_DequeArray_getLength(deque));
}

void test_ctb_DequeArray_pushLast_should_add_element_at_back(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int    val    = 42;
    void * result = ctb_DequeArray_pushLast(deque, &val);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_INT(42, *(int *)result);
    TEST_ASSERT_EQUAL_INT(42, *(int *)ctb_DequeArray_peekFirst(deque));
    TEST_ASSERT_EQUAL_INT(42, *(int *)ctb_DequeArray_peekLast(deque));
    TEST_ASSERT_FALSE(ctb_DequeArray_isEmpty(deque));
    TEST_ASSERT_EQUAL_UINT(1, ctb_DequeArray_getLength(deque));
}

void test_ctb_DequeArray_pushFirst_pushLast_maintains_order(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int v1 = 10, v2 = 20, v3 = 30;
    ctb_DequeArray_pushLast(deque, &v2);
    ctb_DequeArray_pushFirst(deque, &v1);
    ctb_DequeArray_pushLast(deque, &v3);

    TEST_ASSERT_EQUAL_INT(10, *(int *)ctb_DequeArray_peekFirst(deque));
    TEST_ASSERT_EQUAL_INT(30, *(int *)ctb_DequeArray_peekLast(deque));
    TEST_ASSERT_EQUAL_UINT(3, ctb_DequeArray_getLength(deque));
}

void test_ctb_DequeArray_popFirst_should_remove_from_front(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int v1 = 10, v2 = 20;
    ctb_DequeArray_pushLast(deque, &v1);
    ctb_DequeArray_pushLast(deque, &v2);

    void * front = ctb_DequeArray_popFirst(deque);
    TEST_ASSERT_NOT_NULL(front);
    TEST_ASSERT_EQUAL_INT(10, *(int *)front);
    TEST_ASSERT_EQUAL_UINT(1, ctb_DequeArray_getLength(deque));
    TEST_ASSERT_EQUAL_INT(20, *(int *)ctb_DequeArray_peekFirst(deque));

    front = ctb_DequeArray_popFirst(deque);
    TEST_ASSERT_NOT_NULL(front);
    TEST_ASSERT_EQUAL_INT(20, *(int *)front);
    TEST_ASSERT_TRUE(ctb_DequeArray_isEmpty(deque));
}

void test_ctb_DequeArray_popLast_should_remove_from_back(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int v1 = 10, v2 = 20;
    ctb_DequeArray_pushLast(deque, &v1);
    ctb_DequeArray_pushLast(deque, &v2);

    void * back = ctb_DequeArray_popLast(deque);
    TEST_ASSERT_NOT_NULL(back);
    TEST_ASSERT_EQUAL_INT(20, *(int *)back);
    TEST_ASSERT_EQUAL_UINT(1, ctb_DequeArray_getLength(deque));
    TEST_ASSERT_EQUAL_INT(10, *(int *)ctb_DequeArray_peekFirst(deque));
    TEST_ASSERT_EQUAL_INT(10, *(int *)ctb_DequeArray_peekLast(deque));

    back = ctb_DequeArray_popLast(deque);
    TEST_ASSERT_NOT_NULL(back);
    TEST_ASSERT_EQUAL_INT(10, *(int *)back);
    TEST_ASSERT_TRUE(ctb_DequeArray_isEmpty(deque));
}

void test_ctb_DequeArray_popFirst_from_empty_should_return_NULL(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    TEST_ASSERT_NULL(ctb_DequeArray_popFirst(deque));
}

void test_ctb_DequeArray_popLast_from_empty_should_return_NULL(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    TEST_ASSERT_NULL(ctb_DequeArray_popLast(deque));
}

void test_ctb_DequeArray_peekFirst_from_empty_should_return_NULL(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    TEST_ASSERT_NULL(ctb_DequeArray_peekFirst(deque));
}

void test_ctb_DequeArray_peekLast_from_empty_should_return_NULL(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    TEST_ASSERT_NULL(ctb_DequeArray_peekLast(deque));
}

void test_ctb_DequeArray_pushFirst_full_should_return_NULL(void) {
    int                storage[2];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int v1 = 1, v2 = 2, v3 = 3;
    TEST_ASSERT_NOT_NULL(ctb_DequeArray_pushFirst(deque, &v1));
    TEST_ASSERT_NOT_NULL(ctb_DequeArray_pushFirst(deque, &v2));
    TEST_ASSERT_NULL(ctb_DequeArray_pushFirst(deque, &v3));
    TEST_ASSERT_EQUAL_UINT(2, ctb_DequeArray_getLength(deque));
}

void test_ctb_DequeArray_pushLast_full_should_return_NULL(void) {
    int                storage[2];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int v1 = 1, v2 = 2, v3 = 3;
    TEST_ASSERT_NOT_NULL(ctb_DequeArray_pushLast(deque, &v1));
    TEST_ASSERT_NOT_NULL(ctb_DequeArray_pushLast(deque, &v2));
    TEST_ASSERT_NULL(ctb_DequeArray_pushLast(deque, &v3));
    TEST_ASSERT_EQUAL_UINT(2, ctb_DequeArray_getLength(deque));
}

void test_ctb_DequeArray_clear_should_empty_deque(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int v1 = 10, v2 = 20;
    ctb_DequeArray_pushLast(deque, &v1);
    ctb_DequeArray_pushFirst(deque, &v2);
    TEST_ASSERT_EQUAL_UINT(2, ctb_DequeArray_getLength(deque));

    ctb_DequeArray_clear(deque);
    TEST_ASSERT_TRUE(ctb_DequeArray_isEmpty(deque));
    TEST_ASSERT_EQUAL_UINT(0, ctb_DequeArray_getLength(deque));
    TEST_ASSERT_NULL(ctb_DequeArray_peekFirst(deque));
    TEST_ASSERT_NULL(ctb_DequeArray_peekLast(deque));
    TEST_ASSERT_EQUAL_UINT(4, ctb_DequeArray_getCapacity(deque));
}

void test_ctb_DequeArray_pushFirst_popFirst_should_work_LIFO(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int v1 = 10, v2 = 20, v3 = 30;
    ctb_DequeArray_pushFirst(deque, &v1);
    ctb_DequeArray_pushFirst(deque, &v2);
    ctb_DequeArray_pushFirst(deque, &v3);

    TEST_ASSERT_EQUAL_INT(30, *(int *)ctb_DequeArray_popFirst(deque));
    TEST_ASSERT_EQUAL_INT(20, *(int *)ctb_DequeArray_popFirst(deque));
    TEST_ASSERT_EQUAL_INT(10, *(int *)ctb_DequeArray_popFirst(deque));
    TEST_ASSERT_TRUE(ctb_DequeArray_isEmpty(deque));
}

void test_ctb_DequeArray_pushLast_popLast_should_work_LIFO(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int v1 = 10, v2 = 20, v3 = 30;
    ctb_DequeArray_pushLast(deque, &v1);
    ctb_DequeArray_pushLast(deque, &v2);
    ctb_DequeArray_pushLast(deque, &v3);

    TEST_ASSERT_EQUAL_INT(30, *(int *)ctb_DequeArray_popLast(deque));
    TEST_ASSERT_EQUAL_INT(20, *(int *)ctb_DequeArray_popLast(deque));
    TEST_ASSERT_EQUAL_INT(10, *(int *)ctb_DequeArray_popLast(deque));
    TEST_ASSERT_TRUE(ctb_DequeArray_isEmpty(deque));
}

void test_ctb_DequeArray_pushFirst_popLast_should_work_FIFO(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int v1 = 10, v2 = 20, v3 = 30;
    ctb_DequeArray_pushFirst(deque, &v1);
    ctb_DequeArray_pushFirst(deque, &v2);
    ctb_DequeArray_pushFirst(deque, &v3);

    TEST_ASSERT_EQUAL_INT(10, *(int *)ctb_DequeArray_popLast(deque));
    TEST_ASSERT_EQUAL_INT(20, *(int *)ctb_DequeArray_popLast(deque));
    TEST_ASSERT_EQUAL_INT(30, *(int *)ctb_DequeArray_popLast(deque));
    TEST_ASSERT_TRUE(ctb_DequeArray_isEmpty(deque));
}

void test_ctb_DequeArray_wrap_around_pushFirst_popLast(void) {
    int                storage[3];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int v1 = 1, v2 = 2, v3 = 3, v4 = 4;

    ctb_DequeArray_pushLast(deque, &v1);
    ctb_DequeArray_pushLast(deque, &v2);
    ctb_DequeArray_pushLast(deque, &v3);
    TEST_ASSERT_EQUAL_UINT(3, ctb_DequeArray_getLength(deque));

    TEST_ASSERT_EQUAL_INT(1, *(int *)ctb_DequeArray_popFirst(deque));
    TEST_ASSERT_EQUAL_INT(2, *(int *)ctb_DequeArray_popFirst(deque));
    TEST_ASSERT_EQUAL_UINT(1, ctb_DequeArray_getLength(deque));

    ctb_DequeArray_pushLast(deque, &v4);
    TEST_ASSERT_EQUAL_UINT(2, ctb_DequeArray_getLength(deque));

    TEST_ASSERT_EQUAL_INT(3, *(int *)ctb_DequeArray_popFirst(deque));
    TEST_ASSERT_EQUAL_INT(4, *(int *)ctb_DequeArray_popFirst(deque));
    TEST_ASSERT_TRUE(ctb_DequeArray_isEmpty(deque));
}

void test_ctb_DequeArray_wrap_around_pushLast_and_pushFirst(void) {
    int                storage[3];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int v1 = 1, v2 = 2, v3 = 3, v4 = 4, v5 = 5;

    ctb_DequeArray_pushLast(deque, &v1);
    ctb_DequeArray_pushLast(deque, &v2);
    ctb_DequeArray_pushLast(deque, &v3);
    TEST_ASSERT_EQUAL_UINT(3, ctb_DequeArray_getLength(deque));

    TEST_ASSERT_EQUAL_INT(1, *(int *)ctb_DequeArray_popFirst(deque));
    TEST_ASSERT_EQUAL_INT(2, *(int *)ctb_DequeArray_popFirst(deque));
    TEST_ASSERT_EQUAL_UINT(1, ctb_DequeArray_getLength(deque));

    ctb_DequeArray_pushLast(deque, &v4);
    ctb_DequeArray_pushFirst(deque, &v5);

    TEST_ASSERT_EQUAL_INT(5, *(int *)ctb_DequeArray_peekFirst(deque));
    TEST_ASSERT_EQUAL_INT(4, *(int *)ctb_DequeArray_peekLast(deque));

    TEST_ASSERT_EQUAL_INT(5, *(int *)ctb_DequeArray_popFirst(deque));
    TEST_ASSERT_EQUAL_INT(3, *(int *)ctb_DequeArray_popFirst(deque));
    TEST_ASSERT_EQUAL_INT(4, *(int *)ctb_DequeArray_popFirst(deque));
    TEST_ASSERT_TRUE(ctb_DequeArray_isEmpty(deque));
}

void test_ctb_DequeArray_pushFirst_should_return_pointer_to_stored_element(void) {
    int                storage[3];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int    val    = 77;
    void * stored = ctb_DequeArray_pushFirst(deque, &val);
    TEST_ASSERT_EQUAL_PTR(&((int *)storage)[2], stored);

    int    val2    = 88;
    void * stored2 = ctb_DequeArray_pushFirst(deque, &val2);
    TEST_ASSERT_EQUAL_PTR(&((int *)storage)[1], stored2);
}

void test_ctb_DequeArray_pushLast_should_return_pointer_to_stored_element(void) {
    int                storage[3];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int    val    = 77;
    void * stored = ctb_DequeArray_pushLast(deque, &val);
    TEST_ASSERT_EQUAL_PTR(&((int *)storage)[0], stored);

    int    val2    = 88;
    void * stored2 = ctb_DequeArray_pushLast(deque, &val2);
    TEST_ASSERT_EQUAL_PTR(&((int *)storage)[1], stored2);
}

void test_ctb_DequeArray_popFirst_should_return_pointer_to_vacated_slot(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int v1 = 10, v2 = 20;
    ctb_DequeArray_pushLast(deque, &v1);
    ctb_DequeArray_pushLast(deque, &v2);

    void * popped = ctb_DequeArray_popFirst(deque);
    TEST_ASSERT_EQUAL_PTR(&((int *)storage)[0], popped);

    popped = ctb_DequeArray_popFirst(deque);
    TEST_ASSERT_EQUAL_PTR(&((int *)storage)[1], popped);
}

void test_ctb_DequeArray_popLast_should_return_pointer_to_vacated_slot(void) {
    int                storage[4];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    int v1 = 10, v2 = 20;
    ctb_DequeArray_pushLast(deque, &v1);
    ctb_DequeArray_pushLast(deque, &v2);

    void * popped = ctb_DequeArray_popLast(deque);
    TEST_ASSERT_EQUAL_PTR(&((int *)storage)[1], popped);

    popped = ctb_DequeArray_popLast(deque);
    TEST_ASSERT_EQUAL_PTR(&((int *)storage)[0], popped);
}

void test_ctb_DequeArray_should_work_with_struct_elements(void) {
    typedef struct {
        int x;
        int y;
    } Point;

    Point              storage[3];
    ctb_DequeArray_t * deque = ctb_DequeArray_init(ctb_DequeArray(storage));

    Point p1 = { 1, 2 };
    Point p2 = { 3, 4 };
    ctb_DequeArray_pushLast(deque, &p1);
    ctb_DequeArray_pushFirst(deque, &p2);

    Point * first = (Point *)ctb_DequeArray_peekFirst(deque);
    TEST_ASSERT_EQUAL_INT(3, first->x);
    TEST_ASSERT_EQUAL_INT(4, first->y);

    Point * last = (Point *)ctb_DequeArray_peekLast(deque);
    TEST_ASSERT_EQUAL_INT(1, last->x);
    TEST_ASSERT_EQUAL_INT(2, last->y);

    Point * popped = (Point *)ctb_DequeArray_popFirst(deque);
    TEST_ASSERT_EQUAL_INT(3, popped->x);
    TEST_ASSERT_EQUAL_INT(4, popped->y);

    popped = (Point *)ctb_DequeArray_popFirst(deque);
    TEST_ASSERT_EQUAL_INT(1, popped->x);
    TEST_ASSERT_EQUAL_INT(2, popped->y);

    TEST_ASSERT_TRUE(ctb_DequeArray_isEmpty(deque));
}
