/**
 * @defgroup test_ctb_Array test_ctb_Array
 * @ingroup test
 * @{
 * @file
 */
#include "unity.h"

#include "ctb_Array.h"
#include "ctb_ArrayIterator.h"

// Global variable for forEach test
static int test_ctb_Array_forEach_sum = 0;

// Forward declarations for test helper functions
static void accumulate(void * const item);
static bool isSeven(void * const item);
static bool isTen(void * const item);

void setUp(void) {}
void tearDown(void) {}

void test_ctb_Array_init_should_initialize_array(void) {
    ctb_Array_t * array = ctb_Array_init(ctb_Array(ctb_arr(int, 5)));

    TEST_ASSERT_NOT_NULL(array);
    TEST_ASSERT_EQUAL_INT(sizeof(int), ctb_Array_getItemSize(array));
    TEST_ASSERT_EQUAL_INT(5, ctb_Array_getCapacity(array));
}

void test_ctb_Array_get_and_set_should_work_with_integers(void) {
    ctb_Array_t * array = ctb_Array_init(ctb_Array(ctb_arr(int, 3)));

    // Test setting and getting first item
    int value1 = 42;
    ctb_Array_set(array, 0, &value1);
    int * retrieved1 = ctb_Array_get(array, 0);
    TEST_ASSERT_NOT_NULL(retrieved1);
    TEST_ASSERT_EQUAL_INT(42, *retrieved1);

    // Test setting and getting middle item
    int value2 = 99;
    ctb_Array_set(array, 1, &value2);
    int * retrieved2 = ctb_Array_get(array, 1);
    TEST_ASSERT_NOT_NULL(retrieved2);
    TEST_ASSERT_EQUAL_INT(99, *retrieved2);

    // Test setting and getting last item
    int value3 = 123;
    ctb_Array_set(array, 2, &value3);
    int * retrieved3 = ctb_Array_get(array, 2);
    TEST_ASSERT_NOT_NULL(retrieved3);
    TEST_ASSERT_EQUAL_INT(123, *retrieved3);
}

void test_ctb_Array_get_should_return_null_for_out_of_bounds(void) {
    ctb_Array_t * array = ctb_Array_init(ctb_Array(ctb_arr(int, 2)));

    // Test negative index (as size_t, this will be a large number)
    TEST_ASSERT_NULL(ctb_Array_get(array, (size_t)-1));

    // Test index equal to capacity
    TEST_ASSERT_NULL(ctb_Array_get(array, 2));

    // Test index beyond capacity
    TEST_ASSERT_NULL(ctb_Array_get(array, 5));
}

void test_ctb_Array_set_should_do_nothing_for_out_of_bounds(void) {
    ctb_Array_t * array = ctb_Array_init(ctb_Array(ctb_arr(int, 2)));

    int value = 42;
    // These should not change the array contents
    ctb_Array_set(array, (size_t)-1, &value);
    ctb_Array_set(array, 2, &value);
    ctb_Array_set(array, 5, &value);

    // Array should still contain zeros
    TEST_ASSERT_EQUAL_INT(0, *(int *)ctb_Array_get(array, 0));
    TEST_ASSERT_EQUAL_INT(0, *(int *)ctb_Array_get(array, 1));
}

void test_ctb_Array_forEach_should_apply_operation_to_all_items(void) {
    ctb_Array_t * array = ctb_Array_init(ctb_Array(ctb_arr(int, 3)));
    ctb_Array_set(array, 0, &(int){ 1 });
    ctb_Array_set(array, 1, &(int){ 2 });
    ctb_Array_set(array, 2, &(int){ 3 });

    // Reset static variable for this test
    test_ctb_Array_forEach_sum = 0;

    ctb_Array_forEach(array, accumulate);
    TEST_ASSERT_EQUAL_INT(6, test_ctb_Array_forEach_sum); // 1 + 2 + 3 = 6
}

void test_ctb_Array_find_should_return_matching_item(void) {
    ctb_Array_t * array = ctb_Array_init(ctb_Array(ctb_arr(int, 5)));
    ctb_Array_set(array, 0, &(int){ 1 });
    ctb_Array_set(array, 1, &(int){ 7 });
    ctb_Array_set(array, 2, &(int){ 3 });
    ctb_Array_set(array, 3, &(int){ 5 });
    ctb_Array_set(array, 4, &(int){ 11 });
    int * found = ctb_Array_find(array, isSeven);
    TEST_ASSERT_NOT_NULL(found);
    TEST_ASSERT_EQUAL_INT(7, *found);

    int * notFound = ctb_Array_find(array, isTen);
    TEST_ASSERT_NULL(notFound);
}

void test_ctb_Array_should_work_with_structs(void) {
    typedef struct {
        int   id;
        float value;
    } test_Item_t;

    ctb_Array_t * array = ctb_Array_init(ctb_Array(ctb_arr(test_Item_t, 2)));

    test_Item_t value1 = { 42, 3.14f };
    ctb_Array_set(array, 0, &value1);

    test_Item_t * retrieved = ctb_Array_get(array, 0);
    TEST_ASSERT_NOT_NULL(retrieved);
    TEST_ASSERT_EQUAL_INT(42, retrieved->id);
}

void test_ctb_Array_getItemSize_and_getCapacity_should_return_correct_values(void) {
    ctb_Array_t * array = ctb_Array_init(ctb_Array(ctb_arr(double, 4)));

    TEST_ASSERT_EQUAL_INT(sizeof(double), ctb_Array_getItemSize(array));
    TEST_ASSERT_EQUAL_INT(4, ctb_Array_getCapacity(array));
}

// Helper function definitions
static void accumulate(void * const item) {
    test_ctb_Array_forEach_sum += *(int *)item;
}

static bool isSeven(void * const item) {
    return *(int *)item == 7;
}

static bool isTen(void * const item) {
    return *(int *)item == 10;
}

/** @} */
