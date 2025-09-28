#include "s21_decimal.h"
#include "decier.h"

#include <check.h>
#include <limits.h>

void test_s21_from_int_to_decimal_1 (void) {
  s21_decimal result;
  int status = s21_from_int_to_decimal(123, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 123);
  ck_assert_uint_eq(result.fields.negative, SIGN_BIT_POSITIVE);
}
 
void  test_s21_from_int_to_decimal_2(void) {
  s21_decimal result;
  int status = s21_from_int_to_decimal(-456, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 456);
  ck_assert_uint_eq(result.fields.negative, SIGN_BIT_NEGATIVE);
}
 
void test_s21_from_int_to_decimal_3(void) {
  s21_decimal result;
  int status = s21_from_int_to_decimal(0, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.fields.negative, SIGN_BIT_POSITIVE);
}
 
void test_s21_from_int_to_decimal_4(void) {
  s21_decimal result;
  int status = s21_from_int_to_decimal(INT_MAX, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], INT_MAX);
  ck_assert_uint_eq(result.fields.negative, SIGN_BIT_POSITIVE);
}
 
void test_s21_from_int_to_decimal_5(void) {
  s21_decimal result;
  int status = s21_from_int_to_decimal(INT_MIN, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], INT_MIN);
  ck_assert_uint_eq(result.fields.negative, SIGN_BIT_NEGATIVE);
}

START_TEST(testing_from_int_to_decimal) {
    test_s21_from_int_to_decimal_1();
    test_s21_from_int_to_decimal_2();
    test_s21_from_int_to_decimal_3();
    test_s21_from_int_to_decimal_4();
    test_s21_from_int_to_decimal_5();
}

void test_s21_from_float_to_decimal_1(void) {
  s21_decimal result;
  int status = s21_from_float_to_decimal(123.456f, &result);
  ck_assert_int_eq(status, 0);
  float f;
  s21_from_decimal_to_float(result, &f);
  ck_assert_float_eq_tol(f, 123.456f, 1e-6);
}

void test_s21_from_float_to_decimal_2(void) {
  s21_decimal result;
  int status = s21_from_float_to_decimal(-789.123f, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.fields.negative, SIGN_BIT_NEGATIVE);
  float f;
  s21_from_decimal_to_float(result, &f);
  ck_assert_float_eq_tol(f, -789.123f, 1e-6);
}

void test_s21_from_float_to_decimal_3(void) {
  s21_decimal result;
  int status = s21_from_float_to_decimal(0.0f, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.fields.negative, SIGN_BIT_POSITIVE);
}

void test_s21_from_float_to_decimal_4(void) {
  s21_decimal result;
  int status = s21_from_float_to_decimal(1e-20f, &result);
  ck_assert_int_eq(status, 1);
}

void test_s21_from_float_to_decimal_5(void) {
  s21_decimal result;
  int status = s21_from_float_to_decimal(1e30f, &result);
  ck_assert_int_eq(status, 1);
}


START_TEST(testing_from_float_to_decimal) {
    test_s21_from_float_to_decimal_1();
    test_s21_from_float_to_decimal_2();
    test_s21_from_float_to_decimal_3();
    test_s21_from_float_to_decimal_4();
    test_s21_from_float_to_decimal_5();
}


void test_s21_from_decimal_to_int_1(void) {
  s21_decimal src;
  s21_from_int_to_decimal(123, &src);
  int result;
  int status = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(result, 123);
}

void test_s21_from_decimal_to_int_2(void) {
  s21_decimal src;
  s21_from_int_to_decimal(-456, &src);
  int result;
  int status = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(result, -456);
}

void test_s21_from_decimal_to_int_3(void) {
  s21_decimal src = decimal_create(123456, 0, 0, 0);
  src.fields.exponent = 3;
  int result;
  int status = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(result, 123);
}

void test_s21_from_decimal_to_int_4(void) {
  s21_decimal src = decimal_create(UINT_MAX, 0, 0, 0);
  int result;
  int status = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(status, 1);
}

void test_s21_from_decimal_to_int_5(void) {
  s21_decimal src = decimal_create(0, 0, 0, 0);
  int result;
  int status = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(result, 0);
}

START_TEST(testing_from_decimal_to_int) {
    test_s21_from_decimal_to_int_1();
    test_s21_from_decimal_to_int_2();
    test_s21_from_decimal_to_int_3();
    test_s21_from_decimal_to_int_4();
    test_s21_from_decimal_to_int_5();
}


void test_s21_from_decimal_to_float_1(void) {
  s21_decimal src;
  s21_from_float_to_decimal(123.456f, &src);
  float result;
  int status = s21_from_decimal_to_float(src, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_float_eq_tol(result, 123.456f, 1e-6);
}

void test_s21_from_decimal_to_float_2(void) {
  s21_decimal src;
  s21_from_float_to_decimal(-789.123f, &src);
  float result;
  int status = s21_from_decimal_to_float(src, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_float_eq_tol(result, -789.123f, 1e-6);
}

void test_s21_from_decimal_to_float_3(void) {
  s21_decimal src = decimal_create(0, 0, 0, 0);
  float result;
  int status = s21_from_decimal_to_float(src, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_float_eq(result, 0.0f);
}

void test_s21_from_decimal_to_float_4(void) {
  s21_decimal src = decimal_create(123456, 0, 0, 0);
  src.fields.exponent = 3;
  float result;
  int status = s21_from_decimal_to_float(src, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_float_eq_tol(result, 123.456f, 1e-6);
} 

void test_s21_from_decimal_to_float_5(void) {
  s21_decimal src = decimal_create(123456, 0, 0, 0x80000000);
  src.fields.exponent = 3;
  float result;
  int status = s21_from_decimal_to_float(src, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_float_eq_tol(result, -123.456f, 1e-6);
}

START_TEST(testing_from_decimal_to_float) {
    test_s21_from_decimal_to_float_1();
    test_s21_from_decimal_to_float_2();
    test_s21_from_decimal_to_float_3();
    test_s21_from_decimal_to_float_4();
    test_s21_from_decimal_to_float_5();
}

TCase *converters() {
    TCase *tc = tcase_create("Converters testing");
    tcase_add_test(tc, testing_from_int_to_decimal);
    tcase_add_test(tc, testing_from_float_to_decimal);
    tcase_add_test(tc, testing_from_decimal_to_int);
    tcase_add_test(tc, testing_from_decimal_to_float);
    return tc;
}
