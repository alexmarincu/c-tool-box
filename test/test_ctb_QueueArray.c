#include "unity.h"

#include "ctb_QueueArray.h"

void setUp(void) {}
void tearDown(void) {}

void test_ctb_QueueArray_init_should_initialize_queue(void) {
    int storage[4];
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(storage));
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(queue));
    TEST_ASSERT_EQUAL_UINT(0, ctb_QueueArray_getLength(queue));
    TEST_ASSERT_EQUAL_UINT(4, ctb_QueueArray_getCapacity(queue));
    TEST_ASSERT_NULL(ctb_QueueArray_peek(queue));
}

void test_ctb_QueueArray_enqueue_should_add_element(void) {
    int storage[4];
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(storage));

    int val = 42;
    void * result = ctb_QueueArray_enqueue(queue, &val);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_INT(42, *(int *)result);
    TEST_ASSERT_EQUAL_INT(42, *(int *)ctb_QueueArray_peek(queue));
    TEST_ASSERT_FALSE(ctb_QueueArray_isEmpty(queue));
    TEST_ASSERT_EQUAL_UINT(1, ctb_QueueArray_getLength(queue));
}

void test_ctb_QueueArray_dequeue_should_return_front_and_remove(void) {
    int storage[4];
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(storage));

    int v1 = 10, v2 = 20;
    ctb_QueueArray_enqueue(queue, &v1);
    ctb_QueueArray_enqueue(queue, &v2);

    void * front = ctb_QueueArray_dequeue(queue);
    TEST_ASSERT_NOT_NULL(front);
    TEST_ASSERT_EQUAL_INT(10, *(int *)front);
    TEST_ASSERT_EQUAL_UINT(1, ctb_QueueArray_getLength(queue));

    front = ctb_QueueArray_dequeue(queue);
    TEST_ASSERT_NOT_NULL(front);
    TEST_ASSERT_EQUAL_INT(20, *(int *)front);
    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(queue));
    TEST_ASSERT_EQUAL_UINT(0, ctb_QueueArray_getLength(queue));
}

void test_ctb_QueueArray_dequeue_from_empty_should_return_NULL(void) {
    int storage[4];
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(storage));

    TEST_ASSERT_NULL(ctb_QueueArray_dequeue(queue));
}

void test_ctb_QueueArray_peek_should_return_front_without_removing(void) {
    int storage[4];
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(storage));

    int val = 99;
    ctb_QueueArray_enqueue(queue, &val);
    TEST_ASSERT_EQUAL_INT(99, *(int *)ctb_QueueArray_peek(queue));
    TEST_ASSERT_FALSE(ctb_QueueArray_isEmpty(queue));
    TEST_ASSERT_EQUAL_UINT(1, ctb_QueueArray_getLength(queue));
}

void test_ctb_QueueArray_peek_from_empty_should_return_NULL(void) {
    int storage[4];
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(storage));

    TEST_ASSERT_NULL(ctb_QueueArray_peek(queue));
}

void test_ctb_QueueArray_clear_should_empty_queue(void) {
    int storage[4];
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(storage));

    int v1 = 10, v2 = 20;
    ctb_QueueArray_enqueue(queue, &v1);
    ctb_QueueArray_enqueue(queue, &v2);
    TEST_ASSERT_EQUAL_UINT(2, ctb_QueueArray_getLength(queue));

    ctb_QueueArray_clear(queue);
    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(queue));
    TEST_ASSERT_EQUAL_UINT(0, ctb_QueueArray_getLength(queue));
    TEST_ASSERT_NULL(ctb_QueueArray_peek(queue));
    TEST_ASSERT_EQUAL_UINT(4, ctb_QueueArray_getCapacity(queue));
}

void test_ctb_QueueArray_enqueue_full_should_return_NULL(void) {
    int storage[2];
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(storage));

    int v1 = 1, v2 = 2, v3 = 3;
    TEST_ASSERT_NOT_NULL(ctb_QueueArray_enqueue(queue, &v1));
    TEST_ASSERT_NOT_NULL(ctb_QueueArray_enqueue(queue, &v2));
    TEST_ASSERT_NULL(ctb_QueueArray_enqueue(queue, &v3));
    TEST_ASSERT_EQUAL_UINT(2, ctb_QueueArray_getLength(queue));
}

void test_ctb_QueueArray_enqueue_dequeue_cycle_maintains_FIFO_order(void) {
    int storage[4];
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(storage));

    int v1 = 10, v2 = 20, v3 = 30;

    ctb_QueueArray_enqueue(queue, &v1);
    ctb_QueueArray_enqueue(queue, &v2);

    TEST_ASSERT_EQUAL_INT(10, *(int *)ctb_QueueArray_dequeue(queue));

    ctb_QueueArray_enqueue(queue, &v3);

    TEST_ASSERT_EQUAL_INT(20, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_EQUAL_INT(30, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(queue));
}

void test_ctb_QueueArray_enqueue_dequeue_cycle_wraps_around(void) {
    int storage[3];
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(storage));

    int v1 = 1, v2 = 2, v3 = 3, v4 = 4;

    ctb_QueueArray_enqueue(queue, &v1);
    ctb_QueueArray_enqueue(queue, &v2);
    ctb_QueueArray_enqueue(queue, &v3);
    TEST_ASSERT_EQUAL_UINT(3, ctb_QueueArray_getLength(queue));

    TEST_ASSERT_EQUAL_INT(1, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_EQUAL_INT(2, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_EQUAL_UINT(1, ctb_QueueArray_getLength(queue));

    ctb_QueueArray_enqueue(queue, &v4);
    TEST_ASSERT_EQUAL_UINT(2, ctb_QueueArray_getLength(queue));

    TEST_ASSERT_EQUAL_INT(3, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_EQUAL_INT(4, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(queue));
}

void test_ctb_QueueArray_enqueue_should_return_pointer_to_stored_element(void) {
    int storage[3];
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(storage));

    int val = 77;
    void * stored = ctb_QueueArray_enqueue(queue, &val);
    TEST_ASSERT_EQUAL_PTR(&((int *)storage)[0], stored);

    int val2 = 88;
    void * stored2 = ctb_QueueArray_enqueue(queue, &val2);
    TEST_ASSERT_EQUAL_PTR(&((int *)storage)[1], stored2);
}

void test_ctb_QueueArray_dequeue_should_return_pointer_to_vacated_slot(void) {
    int storage[4];
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(storage));

    int v1 = 10, v2 = 20;
    ctb_QueueArray_enqueue(queue, &v1);
    ctb_QueueArray_enqueue(queue, &v2);

    void * popped = ctb_QueueArray_dequeue(queue);
    TEST_ASSERT_EQUAL_PTR(&((int *)storage)[0], popped);

    popped = ctb_QueueArray_dequeue(queue);
    TEST_ASSERT_EQUAL_PTR(&((int *)storage)[1], popped);
}

void test_ctb_QueueArray_should_work_with_struct_elements(void) {
    typedef struct {
        int x;
        int y;
    } Point;

    Point storage[3];
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(storage));

    Point p1 = { 1, 2 };
    Point p2 = { 3, 4 };
    ctb_QueueArray_enqueue(queue, &p1);
    ctb_QueueArray_enqueue(queue, &p2);

    Point * front = (Point *)ctb_QueueArray_peek(queue);
    TEST_ASSERT_EQUAL_INT(1, front->x);
    TEST_ASSERT_EQUAL_INT(2, front->y);

    Point * dequeued = (Point *)ctb_QueueArray_dequeue(queue);
    TEST_ASSERT_EQUAL_INT(1, dequeued->x);
    TEST_ASSERT_EQUAL_INT(2, dequeued->y);

    dequeued = (Point *)ctb_QueueArray_dequeue(queue);
    TEST_ASSERT_EQUAL_INT(3, dequeued->x);
    TEST_ASSERT_EQUAL_INT(4, dequeued->y);

    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(queue));
}
