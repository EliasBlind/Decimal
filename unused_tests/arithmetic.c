#include "s21_decimal.h"

#include <check.h>
#include <limits.h>

void test_s21_add_1(void) {
  s21_decimal a = {{5, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  s21_decimal result;
  int status = s21_add(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 8);
}

void test_s21_add_2(void) {
  s21_decimal a = {{UINT_MAX, 0, 0, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  s21_decimal result;
  int status = s21_add(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 1);
}

void test_s21_add_3(void) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, 0, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  s21_decimal result;
  int status = s21_add(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 1);
}

void test_s21_add_4(void) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  s21_decimal result;
  int status = s21_add(a, b, &result);
  ck_assert_int_eq(status, 1);
}

void test_s21_add_5(void) {
  s21_decimal a = {{5, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal result;
  int status = s21_add(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 5);
}

START_TEST(testing_add) {
    test_s21_add_1();
    test_s21_add_2();
    test_s21_add_3();
    test_s21_add_4();
    test_s21_add_5();
}

void test_s21_sub_1(void) {
  s21_decimal a = {{5, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  s21_decimal result;
  int status = s21_sub(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 2);
}

void test_s21_sub_2(void) {
  s21_decimal a = {{0, 1, 0, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  s21_decimal result;
  int status = s21_sub(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], UINT_MAX);
  ck_assert_uint_eq(result.bits[1], 0);
}

void test_s21_sub_3(void) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  s21_decimal result;
  int status = s21_sub(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], UINT_MAX);
  ck_assert_uint_eq(result.bits[1], UINT_MAX);
  ck_assert_uint_eq(result.bits[2], 0);
}

void test_s21_sub_4(void) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  s21_decimal result;
  int status = s21_sub(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 1);
  ck_assert_uint_eq(sign(result), 1);
}

void test_s21_sub_5(void) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal result;
  int status = s21_sub(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 0);
}

START_TEST(testing_sub) {
    test_s21_sub_1();
    test_s21_sub_2();
    test_s21_sub_3();
    test_s21_sub_4();
    test_s21_sub_5();
}

void test_s21_mul_1(void) {
  s21_decimal a = {{5, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  s21_decimal result;
  int status = s21_mul(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 15);
}

void test_s21_mul_2(void) {
  s21_decimal a = {{UINT_MAX, 0, 0, 0}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal result;
  int status = s21_mul(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], UINT_MAX - 1);
  ck_assert_uint_eq(result.bits[1], 1);
}

void test_s21_mul_3(void) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal result;
  int status = s21_mul(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
}

void test_s21_mul_4(void) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal result;
  int status = s21_mul(a, b, &result);
  ck_assert_int_eq(status, 1);
}

void test_s21_mul_5(void) {
  s21_decimal a = {{5, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal result;
  int status = s21_mul(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 0);
}

START_TEST(testing_mul) {
    test_s21_mul_1();
    test_s21_mul_2();
    test_s21_mul_3();
    test_s21_mul_4();
    test_s21_mul_5();
}

void test_s21_div_1(void) {
  s21_decimal a = {{10, 0, 0, 0}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal result;
  int status = s21_div(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 5);
}

void test_s21_div_2(void) {
  s21_decimal a = {{1, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  s21_decimal result;
  int status = s21_div(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(scale(result), 28);
}

void test_s21_div_3(void) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{5, 0, 0, 0}};
  s21_decimal result;
  int status = s21_div(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], 0);
}

void test_s21_div_4(void) {
  s21_decimal a = {{1, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal result;
  int status = s21_div(a, b, &result);
  ck_assert_int_eq(status, 3);
}

void test_s21_div_5(void) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  s21_decimal result;
  int status = s21_div(a, b, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_uint_eq(result.bits[0], UINT_MAX);
  ck_assert_uint_eq(result.bits[1], UINT_MAX);
  ck_assert_uint_eq(result.bits[2], UINT_MAX);
}

START_TEST(testing_div) {
    test_s21_div_1();
    test_s21_div_2();
    test_s21_div_3();
    test_s21_div_4();
    test_s21_div_5();
}

TCase *arithmetic() {
    TCase *tc = tcase_create("Arithmetic testing");
    tcase_add_test(tc, testing_add);
    tcase_add_test(tc, testing_sub);
    tcase_add_test(tc, testing_mul);
    tcase_add_test(tc, testing_div);
    return tc;
}