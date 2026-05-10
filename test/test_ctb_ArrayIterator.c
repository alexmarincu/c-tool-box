#include "unity.h"

#include "ctb_Array.h"
#include "ctb_ArrayIterator.h"

// Global variable for forEach test
static int test_ctb_ArrayIterator_forEach_sum = 0;

// Test struct for item type
typedef struct {
    int   id;
    float value;
} test_Item_t;

// Forward declarations for test helper functions
static void accumulate(void * const item);
static bool isSeven(void * const item);
static bool isTen(void * const item);
static bool matchesTestItemId(void * const item);

void setUp(void) {}
void tearDown(void) {}

void test_ctb_ArrayIterator_init_should_initialize_iterator(void) {
    ctb_Array_t * array = ctb_Array_init(ctb_Array(ctb_arr(int, 3)));

    ctb_ArrayIterator_t * iterator = ctb_ArrayIterator_init(ctb_obj(ctb_ArrayIterator_t), array);

    TEST_ASSERT_EQUAL_PTR(array, iterator->array);
    TEST_ASSERT_EQUAL_INT(0, iterator->nextIndex);
}

void test_ctb_ArrayIterator_hasNext_and_next_should_iterate_forward(void) {
    ctb_Array_t * array = ctb_Array_init(ctb_Array(ctb_arr(int, 3)));
    ctb_Array_set(array, 0, &(int){ 10 });
    ctb_Array_set(array, 1, &(int){ 20 });
    ctb_Array_set(array, 2, &(int){ 30 });
    ctb_ArrayIterator_t * iterator = ctb_ArrayIterator_init(ctb_obj(ctb_ArrayIterator_t), array);

    TEST_ASSERT_TRUE(ctb_ArrayIterator_hasNext(iterator));
    int * first = ctb_ArrayIterator_next(iterator);
    TEST_ASSERT_NOT_NULL(first);
    TEST_ASSERT_EQUAL_INT(10, *first);

    TEST_ASSERT_TRUE(ctb_ArrayIterator_hasNext(iterator));
    int * second = ctb_ArrayIterator_next(iterator);
    TEST_ASSERT_NOT_NULL(second);
    TEST_ASSERT_EQUAL_INT(20, *second);

    TEST_ASSERT_TRUE(ctb_ArrayIterator_hasNext(iterator));
    int * third = ctb_ArrayIterator_next(iterator);
    TEST_ASSERT_NOT_NULL(third);
    TEST_ASSERT_EQUAL_INT(30, *third);

    TEST_ASSERT_FALSE(ctb_ArrayIterator_hasNext(iterator));
    TEST_ASSERT_NULL(ctb_ArrayIterator_next(iterator));
}

void test_ctb_ArrayIterator_reset_should_reset_iterator_to_beginning(void) {
    ctb_Array_t * array = ctb_Array_init(ctb_Array(ctb_arr(int, 3)));
    ctb_Array_set(array, 0, &(int){ 10 });
    ctb_Array_set(array, 1, &(int){ 20 });
    ctb_Array_set(array, 2, &(int){ 30 });
    ctb_ArrayIterator_t * iterator = ctb_ArrayIterator_init(ctb_obj(ctb_ArrayIterator_t), array);

    // Iterate through all items
    while (ctb_ArrayIterator_hasNext(iterator)) {
        ctb_ArrayIterator_next(iterator);
    }
    TEST_ASSERT_FALSE(ctb_ArrayIterator_hasNext(iterator));

    // Reset and check if it's back at the beginning
    ctb_ArrayIterator_reset(iterator);
    TEST_ASSERT_TRUE(ctb_ArrayIterator_hasNext(iterator));
    int * first = ctb_ArrayIterator_next(iterator);
    TEST_ASSERT_NOT_NULL(first);
    TEST_ASSERT_EQUAL_INT(10, *first);
}

void test_ctb_ArrayIterator_forEach_should_apply_to_all_items(void) {
    ctb_Array_t * array = ctb_Array_init(ctb_Array(ctb_arr(int, 3)));
    ctb_Array_set(array, 0, &(int){ 1 });
    ctb_Array_set(array, 1, &(int){ 2 });
    ctb_Array_set(array, 2, &(int){ 3 });
    ctb_ArrayIterator_t * iterator = ctb_ArrayIterator_init(ctb_obj(ctb_ArrayIterator_t), array);

    // Reset static variable for this test
    test_ctb_ArrayIterator_forEach_sum = 0;

    ctb_ArrayIterator_forEach(iterator, accumulate);
    TEST_ASSERT_EQUAL_INT(6, test_ctb_ArrayIterator_forEach_sum); // 1 + 2 + 3 = 6
}

void test_ctb_ArrayIterator_find_should_return_matching_item(void) {
    ctb_Array_t * array = ctb_Array_init(ctb_Array(ctb_arr(int, 5)));
    ctb_Array_set(array, 0, &(int){ 1 });
    ctb_Array_set(array, 1, &(int){ 3 });
    ctb_Array_set(array, 2, &(int){ 5 });
    ctb_Array_set(array, 3, &(int){ 7 });
    ctb_Array_set(array, 4, &(int){ 9 });
    ctb_ArrayIterator_t * iterator = ctb_ArrayIterator_init(ctb_obj(ctb_ArrayIterator_t), array);

    int * found = ctb_ArrayIterator_find(iterator, isSeven);
    TEST_ASSERT_NOT_NULL(found);
    TEST_ASSERT_EQUAL_INT(7, *found);

    // Reset iterator and test for non-matching item
    ctb_ArrayIterator_init(iterator, array);
    int * notFound = ctb_ArrayIterator_find(iterator, isTen);
    TEST_ASSERT_NULL(notFound);
}

void test_ctb_ArrayIterator_should_work_with_structs(void) {
    ctb_Array_t *         array    = ctb_Array_init(ctb_Array(ctb_arr(test_Item_t, 2)));
    ctb_ArrayIterator_t * iterator = ctb_ArrayIterator_init(ctb_obj(ctb_ArrayIterator_t), array);

    test_Item_t value1 = { 42, 3.14f };
    // We need to set the value through the array directly since we're testing the iterator
    ctb_Array_set(array, 0, &value1);

    // Reset iterator to start from beginning
    ctb_ArrayIterator_init(iterator, array);
    test_Item_t * found = ctb_ArrayIterator_find(iterator, matchesTestItemId);
    TEST_ASSERT_NOT_NULL(found);
    TEST_ASSERT_EQUAL_INT(42, found->id);
}

// Helper function definitions
static void accumulate(void * const item) {
    test_ctb_ArrayIterator_forEach_sum += *((int *)item);
}

static bool isSeven(void * const item) {
    return *((int *)item) == 7;
}

static bool isTen(void * const item) {
    return *((int *)item) == 10;
}

static bool matchesTestItemId(void * const item) {
    (void)item;
    test_Item_t const * s = item;
    return s->id == 42;
}
