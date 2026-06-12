#include "unity.h"

#include "ctb_QueueArray.h"
#include "ctb_Array.h"
#include "ctb_ArrayIterator.h"

void setUp(void) {}
void tearDown(void) {}

void test_ctb_QueueArray_init_should_initialize_queue(void) {
    int data[5];
    ctb_QueueArray_t * queue = ctb_QueueArray(data);
    ctb_QueueArray_init(queue);

    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(queue));
    TEST_ASSERT_EQUAL_UINT32(0, ctb_QueueArray_getLength(queue));
    TEST_ASSERT_EQUAL_UINT32(5, ctb_QueueArray_getCapacity(queue));
    TEST_ASSERT_NULL(ctb_QueueArray_peek(queue));
    TEST_ASSERT_NULL(ctb_QueueArray_dequeue(queue));
}

void test_ctb_QueueArray_init_macro_should_initialize_queue(void) {
    int data[3];
    ctb_QueueArray_t * queue = ctb_QueueArray(data);

    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(queue));
    TEST_ASSERT_EQUAL_UINT32(3, ctb_QueueArray_getCapacity(queue));
}

void test_ctb_QueueArray_enqueue_should_add_value_to_queue(void) {
    int data[5];
    ctb_QueueArray_t * queue = ctb_QueueArray(data);
    ctb_QueueArray_init(queue);

    int val = 42;
    TEST_ASSERT_TRUE(ctb_QueueArray_enqueue(queue, &val));
    TEST_ASSERT_FALSE(ctb_QueueArray_isEmpty(queue));
    TEST_ASSERT_EQUAL_UINT32(1, ctb_QueueArray_getLength(queue));

    int * front = (int *)ctb_QueueArray_peek(queue);
    TEST_ASSERT_NOT_NULL(front);
    TEST_ASSERT_EQUAL_INT(42, *front);
}

void test_ctb_QueueArray_enqueue_dequeue_should_respect_FIFO_order(void) {
    int data[5];
    ctb_QueueArray_t * queue = ctb_QueueArray(data);
    ctb_QueueArray_init(queue);

    int v1 = 10, v2 = 20, v3 = 30;
    ctb_QueueArray_enqueue(queue, &v1);
    ctb_QueueArray_enqueue(queue, &v2);
    ctb_QueueArray_enqueue(queue, &v3);
    TEST_ASSERT_EQUAL_UINT32(3, ctb_QueueArray_getLength(queue));

    int * val = (int *)ctb_QueueArray_dequeue(queue);
    TEST_ASSERT_NOT_NULL(val);
    TEST_ASSERT_EQUAL_INT(10, *val);
    TEST_ASSERT_EQUAL_UINT32(2, ctb_QueueArray_getLength(queue));

    val = (int *)ctb_QueueArray_dequeue(queue);
    TEST_ASSERT_EQUAL_INT(20, *val);
    TEST_ASSERT_EQUAL_UINT32(1, ctb_QueueArray_getLength(queue));

    val = (int *)ctb_QueueArray_dequeue(queue);
    TEST_ASSERT_EQUAL_INT(30, *val);
    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(queue));

    TEST_ASSERT_NULL(ctb_QueueArray_dequeue(queue));
}

void test_ctb_QueueArray_enqueue_should_fail_when_full(void) {
    int data[2];
    ctb_QueueArray_t * queue = ctb_QueueArray(data);
    ctb_QueueArray_init(queue);

    int v1 = 1, v2 = 2, v3 = 3;
    TEST_ASSERT_TRUE(ctb_QueueArray_enqueue(queue, &v1));
    TEST_ASSERT_TRUE(ctb_QueueArray_enqueue(queue, &v2));
    TEST_ASSERT_FALSE(ctb_QueueArray_enqueue(queue, &v3));
    TEST_ASSERT_EQUAL_UINT32(2, ctb_QueueArray_getLength(queue));
}

void test_ctb_QueueArray_peek_should_return_front_without_removing(void) {
    int data[5];
    ctb_QueueArray_t * queue = ctb_QueueArray(data);
    ctb_QueueArray_init(queue);

    int v1 = 100, v2 = 200;
    ctb_QueueArray_enqueue(queue, &v1);
    ctb_QueueArray_enqueue(queue, &v2);

    int * val = (int *)ctb_QueueArray_peek(queue);
    TEST_ASSERT_EQUAL_INT(100, *val);
    TEST_ASSERT_EQUAL_UINT32(2, ctb_QueueArray_getLength(queue));
}

void test_ctb_QueueArray_clear_should_empty_queue(void) {
    int data[5];
    ctb_QueueArray_t * queue = ctb_QueueArray(data);
    ctb_QueueArray_init(queue);

    int v1 = 10, v2 = 20;
    ctb_QueueArray_enqueue(queue, &v1);
    ctb_QueueArray_enqueue(queue, &v2);

    ctb_QueueArray_clear(queue);
    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(queue));
    TEST_ASSERT_EQUAL_UINT32(0, ctb_QueueArray_getLength(queue));
    TEST_ASSERT_NULL(ctb_QueueArray_dequeue(queue));
}

void test_ctb_QueueArray_wrap_around_should_maintain_FIFO_order(void) {
    int data[3];
    ctb_QueueArray_t * queue = ctb_QueueArray(data);
    ctb_QueueArray_init(queue);

    int v1 = 1, v2 = 2, v3 = 3, v4 = 4, v5 = 5;

    ctb_QueueArray_enqueue(queue, &v1);
    ctb_QueueArray_enqueue(queue, &v2);
    ctb_QueueArray_enqueue(queue, &v3);
    TEST_ASSERT_EQUAL_UINT32(3, ctb_QueueArray_getLength(queue));

    TEST_ASSERT_EQUAL_INT(1, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_EQUAL_INT(2, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_EQUAL_UINT32(1, ctb_QueueArray_getLength(queue));

    ctb_QueueArray_enqueue(queue, &v4);
    ctb_QueueArray_enqueue(queue, &v5);
    TEST_ASSERT_EQUAL_UINT32(3, ctb_QueueArray_getLength(queue));

    TEST_ASSERT_EQUAL_INT(3, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_EQUAL_INT(4, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_EQUAL_INT(5, *(int *)ctb_QueueArray_dequeue(queue));
    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(queue));
}

void test_ctb_QueueArray_multiple_types(void) {
    char cdata[3];
    ctb_QueueArray_t * cqueue = ctb_QueueArray(cdata);
    ctb_QueueArray_init(cqueue);
    char ca = 'a', cb = 'b';
    ctb_QueueArray_enqueue(cqueue, &ca);
    ctb_QueueArray_enqueue(cqueue, &cb);
    TEST_ASSERT_EQUAL_INT('a', *(char *)ctb_QueueArray_dequeue(cqueue));
    TEST_ASSERT_EQUAL_INT('b', *(char *)ctb_QueueArray_dequeue(cqueue));
    TEST_ASSERT_TRUE(ctb_QueueArray_isEmpty(cqueue));
}
