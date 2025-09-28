#include "s21_decimal.h"
#include "decier.h"

#include <check.h>
#include <limits.h>

TCase *arithmetic(void)
{
    TCase *tc = tcase_create("Arithmetic testing");
    tcase_add_test(tc, testing_add);
    tcase_add_test(tc, testing_sub);
    tcase_add_test(tc, testing_mul);
    tcase_add_test(tc, testing_div);
    return tc;
}

void add_t1(void)
{
    s21_decimal v1 = decimal_create(0, UINT32_MAX, 0, SIGN_BIT_POSITIVE);
    s21_decimal v2 = decimal_create(0, UINT32_MAX, 0, SIGN_BIT_POSITIVE);
    s21_decimal result;
    uint64_t buffer = UINT32_MAX + UINT32_MAX;
    s21_decimal answer = decimal_create(0, buffer, buffer >> 32, SIGN_BIT_POSITIVE);
    int error = s21_add(v1, v2, &result);
    ck_assert_int_eq(error, OK);
    eq_decimal(result, answer);
}

void add_t2_exponent(void)
{
    s21_decimal v1 = decimal_create(0, UINT32_MAX, 0, SIGN_BIT_POSITIVE);
    s21_decimal v2 = decimal_create(0, UINT32_MAX, 0, SIGN_BIT_POSITIVE);
    s21_decimal result;
    v1.fields.exponent = 6;
    v2.fields.exponent = 2;
    int error = s21_add(v1, v2, &result);
    uint64_t buffer = UINT32_MAX + UINT32_MAX;
    buffer *= v1.fields.exponent - v2.fields.exponent;
    s21_decimal answer = decimal_create(0, buffer, buffer >> 32, SIGN_BIT_POSITIVE);
    answer.fields.exponent = v1.fields.exponent;
    ck_assert_int_eq(error, OK);
    eq_decimal(result, answer);
}

void add_t3_infinity(void)
{
    s21_decimal v1 = decimal_create(UINT32_MAX - 1, UINT32_MAX, UINT32_MAX, SIGN_BIT_POSITIVE);
    s21_decimal v2 = decimal_create(1, 0, 0, SIGN_BIT_POSITIVE);
    s21_decimal result;
    v1.fields.exponent = UINT8_MAX;
    v2.fields.exponent = 2;
    int error = s21_add(v1, v2, &result);
    ck_assert_int_eq(error, INFINITY);
}

void add_t4_low_number(void)
{
    s21_decimal v1 = decimal_create(10, 0, 0, SIGN_BIT_POSITIVE);
    s21_decimal v2 = decimal_create(5, 0, 0, SIGN_BIT_POSITIVE);
    s21_decimal result;
    v2.fields.exponent = 30;
    int error = s21_add(v1, v2, &result);
    s21_decimal answer = decimal_create(11, 0, 0, SIGN_BIT_POSITIVE);
    ck_assert_int_eq(error, OK);
    eq_decimal(result, answer);
}

void add_t5(void)
{
    s21_decimal v1 = decimal_create(0, UINT32_MAX, 0, SIGN_BIT_POSITIVE);
    s21_decimal v2 = decimal_create(0, UINT32_MAX, 0, SIGN_BIT_NEGATIVE);
    s21_decimal result;
    s21_decimal answer = decimal_create(0, 0, 0, SIGN_BIT_POSITIVE);
    int error = s21_add(v1, v2, &result);
    ck_assert_int_eq(error, OK);
    eq_decimal(result, answer);
}

void add_t6(void)
{
    s21_decimal v1 = decimal_create(0, UINT32_MAX, 0, SIGN_BIT_POSITIVE);
    s21_decimal v2 = decimal_create(1, UINT32_MAX, 0, SIGN_BIT_NEGATIVE);
    s21_decimal result;
    s21_decimal answer = decimal_create(1, 0, 0, SIGN_BIT_NEGATIVE);
    int error = s21_add(v1, v2, &result);
    ck_assert_int_eq(error, OK);
    eq_decimal(result, answer);
}

START_TEST(testing_add)
{
    printf("add tests:\n");
    printf("add t1:\n");
    add_t1();
    printf("add t2:\n");
    add_t2_exponent();
    printf("add t3:\n");
    add_t3_infinity();
    printf("add t4:\n");
    add_t4_low_number();
    printf("add t5:\n");
    add_t5();
    printf("add t6:\n");
    add_t6();
}

void sub_t1(void)
{
    s21_decimal v1 = decimal_create(1, UINT32_MAX, 0, SIGN_BIT_POSITIVE);
    s21_decimal v2 = decimal_create(0, UINT32_MAX, 0, SIGN_BIT_POSITIVE);
    s21_decimal result;
    s21_decimal answer = decimal_create(1, 0, 0, SIGN_BIT_POSITIVE);
    int error = s21_sub(v1, v2, &result);
    ck_assert_int_eq(error, OK);
    eq_decimal(result, answer);
}

void sub_t2_exponent(void)
{
    s21_decimal v1 = decimal_create(0, UINT32_MAX, 0, SIGN_BIT_POSITIVE);
    s21_decimal v2 = decimal_create(0, UINT32_MAX, 0, SIGN_BIT_NEGATIVE);
    s21_decimal result;
    v1.fields.exponent = 6;
    v2.fields.exponent = 2;
    int error = s21_sub(v1, v2, &result);
    uint64_t buffer = UINT32_MAX + UINT32_MAX;
    buffer *= v1.fields.exponent - v2.fields.exponent;
    s21_decimal answer = decimal_create(0, buffer, buffer >> 32, SIGN_BIT_POSITIVE);
    answer.fields.exponent = v1.fields.exponent;
    ck_assert_int_eq(error, OK);
    eq_decimal(result, answer);
}

void sub_t3_exponent(void)
{
    s21_decimal v1 = decimal_create(0, UINT32_MAX, 0, SIGN_BIT_NEGATIVE);
    s21_decimal v2 = decimal_create(0, UINT32_MAX, 0, SIGN_BIT_POSITIVE);
    s21_decimal result;
    v1.fields.exponent = 6;
    v2.fields.exponent = 2;
    int error = s21_sub(v1, v2, &result);
    uint64_t buffer = UINT32_MAX + UINT32_MAX;
    buffer *= v1.fields.exponent - v2.fields.exponent;
    s21_decimal answer = decimal_create(0, buffer, buffer >> 32, SIGN_BIT_NEGATIVE);
    answer.fields.exponent = v1.fields.exponent;
    ck_assert_int_eq(error, OK);
    eq_decimal(result, answer);
}

void sub_t4_infinity(void)
{
    s21_decimal v1 = decimal_create(UINT32_MAX - 1, UINT32_MAX, UINT32_MAX, SIGN_BIT_NEGATIVE);
    s21_decimal v2 = decimal_create(1, 0, 0, SIGN_BIT_POSITIVE);
    s21_decimal result;
    v1.fields.exponent = UINT8_MAX;
    v2.fields.exponent = 2;
    int error = s21_sub(v1, v2, &result);
    ck_assert_int_eq(error, NEGATIVE_INFINITY);
}

void sub_t5_low_number(void)
{
    s21_decimal v1 = decimal_create(10, 0, 0, SIGN_BIT_NEGATIVE);
    s21_decimal v2 = decimal_create(5, 0, 0, SIGN_BIT_POSITIVE);
    s21_decimal result;
    v2.fields.exponent = 30;
    int error = s21_sub(v1, v2, &result);
    s21_decimal answer = decimal_create(10, 0, 0, SIGN_BIT_POSITIVE);
    ck_assert_int_eq(error, OK);
    eq_decimal(result, answer);
}

void sub_t6_low_number(void)
{
    s21_decimal v1 = decimal_create(10, 0, 0, SIGN_BIT_NEGATIVE);
    s21_decimal v2 = decimal_create(6, 0, 0, SIGN_BIT_POSITIVE);
    s21_decimal result;
    v2.fields.exponent = 30;
    int error = s21_sub(v1, v2, &result);
    s21_decimal answer = decimal_create(9, 0, 0, SIGN_BIT_POSITIVE);
    ck_assert_int_eq(error, OK);
    eq_decimal(result, answer);
}

START_TEST(testing_sub)
{
    printf("sub tests:\n");
    printf("sub t1:\n");
    sub_t1();
    printf("sub t2:\n");
    sub_t2_exponent();
    printf("sub t3:\n");
    sub_t3_exponent();
    printf("sub t4:\n");
    sub_t4_infinity();
    printf("sub t5:\n");
    sub_t5_low_number();
    printf("sub t6:\n");
    sub_t6_low_number();
}

START_TEST(testing_mul)
{
    printf("mul tests:\n");
}

START_TEST(testing_div)
{
    printf("div tests:\n");
}
