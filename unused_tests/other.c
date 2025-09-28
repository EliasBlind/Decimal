#include "s21_decimal.h"
#include "decier.h"

#include <check.h>
#include <limits.h>

void test_s21_floor_1(void) {
  s21_decimal value= decimal_create(123456, 0, 0, 0);
  value.fields.exponent =  3;
  s21_decimal result;
  int status = s21_floor(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 123);
  ck_assert_uint_eq(result.fields.exponent,  SIGN_BIT_POSITIVE);
}
 

void test_s21_floor_2(void) {
  s21_decimal value= decimal_create(123456, 0, 0, 0x80000000);
  value.fields.exponent = 3;
  s21_decimal result;
  int status = s21_floor(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 124);
  ck_assert_uint_eq(result.fields.negative, SIGN_BIT_NEGATIVE);
}
 

void test_s21_floor_3(void) {
  s21_decimal value= decimal_create(0, 0, 0, 0);
  value.fields.exponent =  2;
  s21_decimal result;
  int status = s21_floor(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.fields.exponent,  SIGN_BIT_POSITIVE);
}
 

void test_s21_floor_4(void) {
  s21_decimal value= decimal_create(999999, 0, 0, 0);
  value.fields.exponent =  3;
  s21_decimal result;
  int status = s21_floor(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 999);
}
 

void test_s21_floor_5(void) {
  s21_decimal value= decimal_create(1000, 0, 0, 0);
  value.fields.exponent =  1;
  s21_decimal result;
  int status = s21_floor(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 100);
}

START_TEST(testing_floor) {
    test_s21_floor_1();
    test_s21_floor_2();
    test_s21_floor_3();
    test_s21_floor_4();
    test_s21_floor_5();
}

void test_s21_round_1(void) {
  s21_decimal value= decimal_create(123456, 0, 0, 0);
  value.fields.exponent =  3;
  s21_decimal result;
  int status = s21_round(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 123);
}
 

void test_s21_round_2(void) {
  s21_decimal value= decimal_create(123556, 0, 0, 0);
  value.fields.exponent =  3;
  s21_decimal result;
  int status = s21_round(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 124);
}
 

void test_s21_round_3(void) {
  s21_decimal value= decimal_create(123556, 0, 0, 0x80000000);
  value.fields.exponent =  3;
  s21_decimal result;
  int status = s21_round(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 124);
  ck_assert_uint_eq(result.fields.negative, SIGN_BIT_NEGATIVE);
}
 

void test_s21_round_4(void) {
  s21_decimal value= decimal_create(0, 0, 0, 0);
  value.fields.exponent =  2;
  s21_decimal result;
  int status = s21_round(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 0);
}

void test_s21_round_5(void) {
  s21_decimal value= decimal_create(5, 0, 0, 0);
  value.fields.exponent =  1;
  s21_decimal result;
  int status = s21_round(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 1);
}

START_TEST(testing_round) {
    test_s21_round_1();
    test_s21_round_2();
    test_s21_round_3();
    test_s21_round_4();
    test_s21_round_5();
}


void test_s21_truncate_1(void) {
  s21_decimal value= decimal_create(123456, 0, 0, 0);
  value.fields.exponent =  3;
  s21_decimal result;
  int status = s21_truncate(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 123);
  ck_assert_uint_eq(result.fields.exponent,  SIGN_BIT_POSITIVE);
}
 

void test_s21_truncate_2(void) {
  s21_decimal value= decimal_create(123456, 0, 0, 0x80000000);
  value.fields.exponent =  3;
  s21_decimal result;
  int status = s21_truncate(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 123);
  ck_assert_uint_eq(result.fields.negative, SIGN_BIT_NEGATIVE);
}
 

void test_s21_truncate_3(void) {
  s21_decimal value= decimal_create(0, 0, 0, 0);
  value.fields.exponent =  2;
  s21_decimal result;
  int status = s21_truncate(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 0);
}
 

void test_s21_truncate_4(void) {
  s21_decimal value= decimal_create(999999, 0, 0, 0);
  value.fields.exponent =  3;
  s21_decimal result;
  int status = s21_truncate(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 999);
}
 

void test_s21_truncate_5(void) {
  s21_decimal value= decimal_create(1000, 0, 0, 0);
  value.fields.exponent =  1;
  s21_decimal result;
  int status = s21_truncate(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 100);
}

START_TEST(testing_truncate) {
    test_s21_truncate_1();
    test_s21_truncate_2();
    test_s21_truncate_3();
    test_s21_truncate_4();
    test_s21_truncate_5();
}


void test_s21_negate_1(void) {
  s21_decimal value= decimal_create(123, 0, 0, 0);
  s21_decimal result;
  int status = s21_negate(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 123);
  ck_assert_uint_eq(result.fields.negative, SIGN_BIT_NEGATIVE);
}
 

void test_s21_negate_2(void) {
  s21_decimal value= decimal_create(456, 0, 0, 0x80000000);
  s21_decimal result;
  int status = s21_negate(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 456);
  ck_assert_uint_eq(result.fields.negative, 0);
}
 

void test_s21_negate_3(void) {
  s21_decimal value= decimal_create(0, 0, 0, 0);
  s21_decimal result;
  int status = s21_negate(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.fields.negative, 0);
}
 

void test_s21_negate_4(void) {
  s21_decimal value= decimal_create(UINT_MAX, UINT_MAX, UINT_MAX, 0);
  s21_decimal result;
  int status = s21_negate(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], UINT_MAX);
  ck_assert_uint_eq(result.bits[1], UINT_MAX);
  ck_assert_uint_eq(result.bits[2], UINT_MAX);
  ck_assert_uint_eq(result.fields.negative, SIGN_BIT_NEGATIVE);
}
 

void test_s21_negate_5(void) {
  s21_decimal value= decimal_create(1, 0, 0, 0);
  value.fields.exponent =  2;
  s21_decimal result;
  int status = s21_negate(value, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 1);
  ck_assert_uint_eq(result.fields.exponent, 2);
  ck_assert_uint_eq(result.fields.negative, SIGN_BIT_NEGATIVE);
}
 

START_TEST(testing_negate) {
    test_s21_negate_1();
    test_s21_negate_2();
    test_s21_negate_3();
    test_s21_negate_4();
    test_s21_negate_5();
}

TCase *other() {
    TCase *tc = tcase_create("Other testing");
    tcase_add_test(tc, testing_floor);
    tcase_add_test(tc, testing_round);
    tcase_add_test(tc, testing_truncate);
    tcase_add_test(tc, testing_negate);
    return tc;
}
