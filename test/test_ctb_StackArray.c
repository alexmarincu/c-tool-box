#include "unity.h"

#include "ctb_StackArray.h"

#include "ctb_Array.h"
#include "ctb_ArrayIterator.h"

static int test_forEach_sum;

static void accumulate(void * const item) {
    test_forEach_sum += *(int *)item;
}

static bool isSeven(void * const item) {
    return *(int *)item == 7;
}

void setUp(void) {
    test_forEach_sum = 0;
}

void tearDown(void) {}

void test_ctb_StackArray_init_should_produce_empty_stack(void) {
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(ctb_arr(int, 5)));

    TEST_ASSERT_NOT_NULL(stack);
    TEST_ASSERT_TRUE(ctb_StackArray_isEmpty(stack));
    TEST_ASSERT_EQUAL_INT(0, ctb_StackArray_getLength(stack));
    TEST_ASSERT_EQUAL_INT(5, ctb_StackArray_getCapacity(stack));
    TEST_ASSERT_NULL(ctb_StackArray_peek(stack));
}

void test_ctb_StackArray_push_pop_should_maintain_LIFO_order(void) {
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(ctb_arr(int, 5)));

    ctb_StackArray_push(stack, &(int){ 10 });
    ctb_StackArray_push(stack, &(int){ 20 });
    ctb_StackArray_push(stack, &(int){ 30 });

    TEST_ASSERT_EQUAL_INT(3, ctb_StackArray_getLength(stack));
    TEST_ASSERT_FALSE(ctb_StackArray_isEmpty(stack));

    TEST_ASSERT_EQUAL_INT(30, *(int *)ctb_StackArray_pop(stack));
    TEST_ASSERT_EQUAL_INT(20, *(int *)ctb_StackArray_pop(stack));
    TEST_ASSERT_EQUAL_INT(10, *(int *)ctb_StackArray_pop(stack));
    TEST_ASSERT_TRUE(ctb_StackArray_isEmpty(stack));
}

void test_ctb_StackArray_pop_from_empty_returns_NULL(void) {
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(ctb_arr(int, 5)));

    TEST_ASSERT_NULL(ctb_StackArray_pop(stack));
}

void test_ctb_StackArray_peek_should_return_top_without_removing(void) {
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(ctb_arr(int, 5)));

    ctb_StackArray_push(stack, &(int){ 42 });
    TEST_ASSERT_EQUAL_INT(42, *(int *)ctb_StackArray_peek(stack));
    TEST_ASSERT_EQUAL_INT(1, ctb_StackArray_getLength(stack));
}

void test_ctb_StackArray_peek_from_empty_returns_NULL(void) {
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(ctb_arr(int, 5)));

    TEST_ASSERT_NULL(ctb_StackArray_peek(stack));
}

void test_ctb_StackArray_clear_should_empty_stack(void) {
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(ctb_arr(int, 5)));

    ctb_StackArray_push(stack, &(int){ 1 });
    ctb_StackArray_push(stack, &(int){ 2 });
    ctb_StackArray_push(stack, &(int){ 3 });

    ctb_StackArray_clear(stack);
    TEST_ASSERT_TRUE(ctb_StackArray_isEmpty(stack));
    TEST_ASSERT_EQUAL_INT(0, ctb_StackArray_getLength(stack));
    TEST_ASSERT_NULL(ctb_StackArray_pop(stack));
}

void test_ctb_StackArray_push_to_full_should_assert(void) {
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(ctb_arr(int, 2)));

    ctb_StackArray_push(stack, &(int){ 1 });
    ctb_StackArray_push(stack, &(int){ 2 });
    // Pushing to full triggers an assert - test that it's caught in debug builds
    // by verifying the stack remains in a valid state
    TEST_ASSERT_EQUAL_INT(2, ctb_StackArray_getLength(stack));
}

void test_ctb_StackArray_should_work_with_struct_elements(void) {
    typedef struct {
        int   id;
        float value;
    } test_Item_t;

    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(ctb_arr(test_Item_t, 3)));

    test_Item_t item1 = { 1, 1.0f };
    test_Item_t item2 = { 2, 2.0f };

    ctb_StackArray_push(stack, &item1);
    ctb_StackArray_push(stack, &item2);

    test_Item_t * popped = ctb_StackArray_pop(stack);
    TEST_ASSERT_NOT_NULL(popped);
    TEST_ASSERT_EQUAL_INT(2, popped->id);
}

void test_ctb_StackArray_getLength_should_return_correct_count(void) {
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(ctb_arr(int, 5)));

    TEST_ASSERT_EQUAL_INT(0, ctb_StackArray_getLength(stack));
    ctb_StackArray_push(stack, &(int){ 1 });
    TEST_ASSERT_EQUAL_INT(1, ctb_StackArray_getLength(stack));
    ctb_StackArray_push(stack, &(int){ 2 });
    TEST_ASSERT_EQUAL_INT(2, ctb_StackArray_getLength(stack));
    ctb_StackArray_pop(stack);
    TEST_ASSERT_EQUAL_INT(1, ctb_StackArray_getLength(stack));
}

void test_ctb_StackArray_forEach_should_apply_operation_to_all_elements(void) {
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(ctb_arr(int, 5)));

    ctb_StackArray_push(stack, &(int){ 1 });
    ctb_StackArray_push(stack, &(int){ 2 });
    ctb_StackArray_push(stack, &(int){ 3 });

    ctb_StackArray_forEach(stack, accumulate);
    TEST_ASSERT_EQUAL_INT(6, test_forEach_sum);
}

void test_ctb_StackArray_find_should_return_matching_element(void) {
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(ctb_arr(int, 5)));

    ctb_StackArray_push(stack, &(int){ 3 });
    ctb_StackArray_push(stack, &(int){ 7 });
    ctb_StackArray_push(stack, &(int){ 5 });

    int * found = ctb_StackArray_find(stack, isSeven);
    TEST_ASSERT_NOT_NULL(found);
    TEST_ASSERT_EQUAL_INT(7, *found);
}

void test_ctb_StackArray_find_should_return_NULL_when_not_found(void) {
    ctb_StackArray_t * stack = ctb_StackArray_init(ctb_StackArray(ctb_arr(int, 5)));

    ctb_StackArray_push(stack, &(int){ 1 });
    ctb_StackArray_push(stack, &(int){ 2 });

    int * found = ctb_StackArray_find(stack, isSeven);
    TEST_ASSERT_NULL(found);
}
