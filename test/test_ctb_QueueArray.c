#include "unity.h"

#include "ctb_QueueArray.h"

void setUp(void) {}
void tearDown(void) {}

void test_ctb_QueueArray_init_should_initialize_queue(void) {
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(ctb_arr(int, 5)));

    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(queue));
    TEST_ASSERT_EQUAL_INT(0, ctb_QueueArray_getLength(queue));
    TEST_ASSERT_EQUAL_INT(5, ctb_QueueArray_getCapacity(queue));
}

void test_ctb_QueueArray_enqueue_should_add_elements(void) {
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(ctb_arr(int, 3)));

    int val = 10;
    ctb_QueueArray_enqueue(queue, &val);

    TEST_ASSERT_FALSE(ctb_QueueArray_isEmpty(queue));
    TEST_ASSERT_EQUAL_INT(1, ctb_QueueArray_getLength(queue));
}

void test_ctb_QueueArray_enqueue_should_copy_value(void) {
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(ctb_arr(int, 3)));

    int val = 42;
    ctb_QueueArray_enqueue(queue, &val);

    int * front = ctb_QueueArray_peek(queue);
    TEST_ASSERT_NOT_NULL(front);
    TEST_ASSERT_EQUAL_INT(42, *front);
}

void test_ctb_QueueArray_dequeue_should_return_and_remove_front(void) {
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(ctb_arr(int, 3)));

    int val1 = 10;
    int val2 = 20;
    ctb_QueueArray_enqueue(queue, &val1);
    ctb_QueueArray_enqueue(queue, &val2);

    int * result = ctb_QueueArray_dequeue(queue);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_INT(10, *result);
    TEST_ASSERT_EQUAL_INT(1, ctb_QueueArray_getLength(queue));

    result = ctb_QueueArray_dequeue(queue);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_INT(20, *result);
    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(queue));
}

void test_ctb_QueueArray_dequeue_should_return_null_when_empty(void) {
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(ctb_arr(int, 3)));

    TEST_ASSERT_NULL(ctb_QueueArray_dequeue(queue));
}

void test_ctb_QueueArray_peek_should_return_front_without_removing(void) {
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(ctb_arr(int, 3)));

    int val = 99;
    ctb_QueueArray_enqueue(queue, &val);

    int * first = ctb_QueueArray_peek(queue);
    TEST_ASSERT_NOT_NULL(first);
    TEST_ASSERT_EQUAL_INT(99, *first);

    // Peek again should return same value
    int * second = ctb_QueueArray_peek(queue);
    TEST_ASSERT_EQUAL_PTR(first, second);
    TEST_ASSERT_EQUAL_INT(1, ctb_QueueArray_getLength(queue));
}

void test_ctb_QueueArray_peek_should_return_null_when_empty(void) {
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(ctb_arr(int, 3)));

    TEST_ASSERT_NULL(ctb_QueueArray_peek(queue));
}

void test_ctb_QueueArray_clear_should_reset_queue(void) {
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(ctb_arr(int, 3)));

    int val1 = 1;
    int val2 = 2;
    ctb_QueueArray_enqueue(queue, &val1);
    ctb_QueueArray_enqueue(queue, &val2);

    ctb_QueueArray_clear(queue);
    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(queue));
    TEST_ASSERT_EQUAL_INT(0, ctb_QueueArray_getLength(queue));
    TEST_ASSERT_NULL(ctb_QueueArray_dequeue(queue));
}

void test_ctb_QueueArray_enqueue_should_wrap_around(void) {
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(ctb_arr(int, 3)));

    int val1 = 1;
    int val2 = 2;
    int val3 = 3;
    ctb_QueueArray_enqueue(queue, &val1);
    ctb_QueueArray_enqueue(queue, &val2);
    ctb_QueueArray_enqueue(queue, &val3);

    TEST_ASSERT_TRUE(ctb_QueueArray_getLength(queue) == 3);

    // Dequeue 2 elements to advance head
    ctb_QueueArray_dequeue(queue);
    ctb_QueueArray_dequeue(queue);
    TEST_ASSERT_EQUAL_INT(1, ctb_QueueArray_getLength(queue));

    // Enqueue 2 more — these should wrap around
    int val4 = 4;
    int val5 = 5;
    ctb_QueueArray_enqueue(queue, &val4);
    ctb_QueueArray_enqueue(queue, &val5);

    TEST_ASSERT_EQUAL_INT(3, ctb_QueueArray_getLength(queue));

    // Verify FIFO order is preserved: 3, 4, 5
    TEST_ASSERT_EQUAL_INT(3, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_EQUAL_INT(4, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_EQUAL_INT(5, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(queue));
}

void test_ctb_QueueArray_enqueue_to_full_should_not_insert(void) {
    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(ctb_arr(int, 2)));

    int val1 = 1;
    int val2 = 2;
    int val3 = 3;
    ctb_QueueArray_enqueue(queue, &val1);
    ctb_QueueArray_enqueue(queue, &val2);

    // Queue is full; enqueue should do nothing
    ctb_QueueArray_enqueue(queue, &val3);
    TEST_ASSERT_EQUAL_INT(2, ctb_QueueArray_getLength(queue));

    TEST_ASSERT_EQUAL_INT(1, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_EQUAL_INT(2, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_NULL(ctb_QueueArray_dequeue(queue));
}

void test_ctb_QueueArray_should_work_with_structs(void) {
    typedef struct {
        int id;
        float value;
    } test_Item_t;

    ctb_QueueArray_t * queue = ctb_QueueArray_init(ctb_QueueArray(ctb_arr(test_Item_t, 3)));

    test_Item_t item1 = { 42, 3.14f };
    ctb_QueueArray_enqueue(queue, &item1);

    test_Item_t * front = ctb_QueueArray_peek(queue);
    TEST_ASSERT_NOT_NULL(front);
    TEST_ASSERT_EQUAL_INT(42, front->id);
}
