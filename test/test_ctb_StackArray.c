#include "unity.h"

#include "ctb_StackArray.h"

void setUp(void) {}
void tearDown(void) {}

void test_ctb_StackArray_init_should_initialize_stack(void) {
    int storage[4];
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(storage));
    TEST_ASSERT_NOT_NULL(stack);
    TEST_ASSERT_TRUE(ctb_StackArray_isEmpty(stack));
    TEST_ASSERT_EQUAL_UINT(0, ctb_StackArray_getLength(stack));
    TEST_ASSERT_NULL(ctb_StackArray_peek(stack));
}

void test_ctb_StackArray_push_should_add_element(void) {
    int storage[4];
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(storage));

    int val = 42;
    void * result = ctb_StackArray_push(stack, &val);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_INT(42, *(int *)result);
    TEST_ASSERT_EQUAL_INT(42, *(int *)ctb_StackArray_peek(stack));
    TEST_ASSERT_FALSE(ctb_StackArray_isEmpty(stack));
    TEST_ASSERT_EQUAL_UINT(1, ctb_StackArray_getLength(stack));
}

void test_ctb_StackArray_push_should_maintain_LIFO_order(void) {
    int storage[4];
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(storage));

    int v1 = 10, v2 = 20, v3 = 30;
    ctb_StackArray_push(stack, &v1);
    ctb_StackArray_push(stack, &v2);
    ctb_StackArray_push(stack, &v3);

    TEST_ASSERT_EQUAL_INT(30, *(int *)ctb_StackArray_peek(stack));
    TEST_ASSERT_EQUAL_UINT(3, ctb_StackArray_getLength(stack));
}

void test_ctb_StackArray_pop_should_return_and_remove_top(void) {
    int storage[4];
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(storage));

    int v1 = 10, v2 = 20, v3 = 30;
    ctb_StackArray_push(stack, &v1);
    ctb_StackArray_push(stack, &v2);
    ctb_StackArray_push(stack, &v3);

    TEST_ASSERT_EQUAL_INT(30, *(int *)ctb_StackArray_pop(stack));
    TEST_ASSERT_EQUAL_UINT(2, ctb_StackArray_getLength(stack));
    TEST_ASSERT_EQUAL_INT(20, *(int *)ctb_StackArray_peek(stack));

    TEST_ASSERT_EQUAL_INT(20, *(int *)ctb_StackArray_pop(stack));
    TEST_ASSERT_EQUAL_UINT(1, ctb_StackArray_getLength(stack));

    TEST_ASSERT_EQUAL_INT(10, *(int *)ctb_StackArray_pop(stack));
    TEST_ASSERT_TRUE(ctb_StackArray_isEmpty(stack));
    TEST_ASSERT_EQUAL_UINT(0, ctb_StackArray_getLength(stack));
}

void test_ctb_StackArray_pop_from_empty_should_return_NULL(void) {
    int storage[4];
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(storage));

    TEST_ASSERT_NULL(ctb_StackArray_pop(stack));
}

void test_ctb_StackArray_peek_should_return_top_without_removing(void) {
    int storage[4];
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(storage));

    int val = 99;
    ctb_StackArray_push(stack, &val);
    TEST_ASSERT_EQUAL_INT(99, *(int *)ctb_StackArray_peek(stack));
    TEST_ASSERT_FALSE(ctb_StackArray_isEmpty(stack));
    TEST_ASSERT_EQUAL_UINT(1, ctb_StackArray_getLength(stack));
}

void test_ctb_StackArray_peek_from_empty_should_return_NULL(void) {
    int storage[4];
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(storage));

    TEST_ASSERT_NULL(ctb_StackArray_peek(stack));
}

void test_ctb_StackArray_clear_should_empty_stack(void) {
    int storage[4];
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(storage));

    int v1 = 10, v2 = 20;
    ctb_StackArray_push(stack, &v1);
    ctb_StackArray_push(stack, &v2);
    TEST_ASSERT_EQUAL_UINT(2, ctb_StackArray_getLength(stack));

    ctb_StackArray_clear(stack);
    TEST_ASSERT_TRUE(ctb_StackArray_isEmpty(stack));
    TEST_ASSERT_EQUAL_UINT(0, ctb_StackArray_getLength(stack));
    TEST_ASSERT_NULL(ctb_StackArray_peek(stack));
}

void test_ctb_StackArray_push_full_should_return_NULL(void) {
    int storage[2];
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(storage));

    int v1 = 1, v2 = 2, v3 = 3;
    TEST_ASSERT_NOT_NULL(ctb_StackArray_push(stack, &v1));
    TEST_ASSERT_NOT_NULL(ctb_StackArray_push(stack, &v2));
    TEST_ASSERT_NULL(ctb_StackArray_push(stack, &v3));
    TEST_ASSERT_EQUAL_UINT(2, ctb_StackArray_getLength(stack));
}

void test_ctb_StackArray_should_work_with_struct_elements(void) {
    typedef struct {
        int x;
        int y;
    } Point;

    Point storage[3];
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(storage));

    Point p1 = { 1, 2 };
    Point p2 = { 3, 4 };
    ctb_StackArray_push(stack, &p1);
    ctb_StackArray_push(stack, &p2);

    Point * top = (Point *)ctb_StackArray_peek(stack);
    TEST_ASSERT_EQUAL_INT(3, top->x);
    TEST_ASSERT_EQUAL_INT(4, top->y);

    Point * popped = (Point *)ctb_StackArray_pop(stack);
    TEST_ASSERT_EQUAL_INT(3, popped->x);
    TEST_ASSERT_EQUAL_INT(4, popped->y);

    popped = (Point *)ctb_StackArray_pop(stack);
    TEST_ASSERT_EQUAL_INT(1, popped->x);
    TEST_ASSERT_EQUAL_INT(2, popped->y);

    TEST_ASSERT_TRUE(ctb_StackArray_isEmpty(stack));
}

void test_ctb_StackArray_push_should_return_pointer_to_stored_element(void) {
    int storage[4];
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(storage));

    int val = 77;
    void * stored = ctb_StackArray_push(stack, &val);
    TEST_ASSERT_EQUAL_PTR(
        &((int *)storage)[0], stored
    );

    int val2 = 88;
    void * stored2 = ctb_StackArray_push(stack, &val2);
    TEST_ASSERT_EQUAL_PTR(
        &((int *)storage)[1], stored2
    );
}

void test_ctb_StackArray_pop_should_return_pointer_to_vacated_slot(void) {
    int storage[4];
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(storage));

    int v1 = 10, v2 = 20;
    ctb_StackArray_push(stack, &v1);
    ctb_StackArray_push(stack, &v2);

    void * popped = ctb_StackArray_pop(stack);
    TEST_ASSERT_EQUAL_PTR(&((int *)storage)[1], popped);

    popped = ctb_StackArray_pop(stack);
    TEST_ASSERT_EQUAL_PTR(&((int *)storage)[0], popped);
}
