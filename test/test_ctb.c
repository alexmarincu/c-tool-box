#include <stdint.h>

#include "unity.h"

#include "ctb.h"

void setUp(void) {}
void tearDown(void) {}

void test_ctb_arr_should_create_zero_initialized_array(void) {
    uint32_t * const arr = ctb_arr(uint32_t, 5);
    for (size_t i = 0; i < 5; i++) {
        TEST_ASSERT_EQUAL_UINT32(0, arr[i]);
    }
}

void test_ctb_obj_should_create_zero_initialized_object(void) {
    typedef struct {
        uint32_t a;
        uint32_t b;
    } test_Obj_t;

    test_Obj_t const * const obj = ctb_obj(test_Obj_t);
    TEST_ASSERT_EQUAL_UINT32(0, obj->a);
    TEST_ASSERT_EQUAL_UINT32(0, obj->b);
}

void test_ctb_capacityOf_should_return_array_length(void) {
    uint32_t const arr1[10] = { 0 };
    TEST_ASSERT_EQUAL_INT(10, ctb_capacityOf(arr1));

    int8_t const arr2[5] = { 0 };
    TEST_ASSERT_EQUAL_INT(5, ctb_capacityOf(arr2));
}

void test_ctb_containerOf_should_return_address_of_containing_object(void) {
    typedef struct {
        uint32_t a;
        uint32_t b;
        uint32_t c;
    } test_Obj_t;

    test_Obj_t obj = { .a = 1, .b = 2, .c = 3 };

    TEST_ASSERT_EQUAL_PTR(&obj, ctb_containerOf(&obj.a, test_Obj_t, a));
    TEST_ASSERT_EQUAL_PTR(&obj, ctb_containerOf(&obj.b, test_Obj_t, b));
    TEST_ASSERT_EQUAL_PTR(&obj, ctb_containerOf(&obj.c, test_Obj_t, c));
}

void test_ctb_alignOf_should_return_alignment(void) {
    TEST_ASSERT_EQUAL_INT(ctb_alignOf(char), ctb_alignOf(char));
    TEST_ASSERT_GREATER_THAN_INT(0, ctb_alignOf(int));
    TEST_ASSERT_EQUAL_INT(offsetof(struct { char c; uint32_t member; }, member), ctb_alignOf(uint32_t));
    TEST_ASSERT_EQUAL_INT(4, ctb_alignOf(uint32_t));
}

ctb_staticAssert(1 == 1, test_static_assert_true);

void test_ctb_staticAssert_should_compile(void) {
    // If it compiles, the static assert passed
}
