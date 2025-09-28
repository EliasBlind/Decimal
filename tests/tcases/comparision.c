#include "s21_decimal.h"
# include "decier.h"

#include <check.h>

void test_s21_is_less_1 (void) {
  s21_decimal a = decimal_create(5, 0, 0, 0);
  s21_decimal b = decimal_create (3, 0, 0, 0);
  int result = s21_is_less(a, b);
  ck_assert_int_eq(result, FALSE);
}

void test_s21_is_less_2 (void) {
  s21_decimal a = decimal_create (3, 0, 0, 0);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  int result = s21_is_less(a, b);
  ck_assert_int_eq(result, TRUE);
}

void test_s21_is_less_3 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  int result = s21_is_less(a, b);
  ck_assert_int_eq(result, FALSE);
}

void test_s21_is_less_4 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0x80000000);
  s21_decimal b = decimal_create (3, 0, 0, 0);
  int result = s21_is_less(a, b);
  ck_assert_int_eq(result, TRUE);
}

void test_s21_is_less_5 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (3, 0, 0, 0x80000000);
  int result = s21_is_less(a, b);
  ck_assert_int_eq(result, FALSE);
}

START_TEST(testing_is_less) {
    test_s21_is_less_1();
    test_s21_is_less_2();
    test_s21_is_less_3();
    test_s21_is_less_4();
    test_s21_is_less_5();
}
END_TEST

void test_s21_is_less_or_equal_1 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  int result = s21_is_less_or_equal(a, b);
  ck_assert_int_eq(result, TRUE);
}

void test_s21_is_less_or_equal_2 (void) {
  s21_decimal a = decimal_create (4, 0, 0, 0);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  int result = s21_is_less_or_equal(a, b);
  ck_assert_int_eq(result, TRUE);
}

void test_s21_is_less_or_equal_3 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (4, 0, 0, 0);
  int result = s21_is_less_or_equal(a, b);
  ck_assert_int_eq(result, FALSE);
}

void test_s21_is_less_or_equal_4 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0x80000000);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  int result = s21_is_less_or_equal(a, b);
  ck_assert_int_eq(result, TRUE);
}

void test_s21_is_less_or_equal_5 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (5, 0, 0, 0x80000000);
  int result = s21_is_less_or_equal(a, b);
  ck_assert_int_eq(result, FALSE);
}

START_TEST(testing_is_less_or_equal) {
    test_s21_is_less_or_equal_1();
    test_s21_is_less_or_equal_2();
    test_s21_is_less_or_equal_3();
    test_s21_is_less_or_equal_4();
    test_s21_is_less_or_equal_5();
}
END_TEST

void test_s21_is_greater_1 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (3, 0, 0, 0);
  int result = s21_is_greater(a, b);
  ck_assert_int_eq(result, TRUE);
}

void test_s21_is_greater_2 (void) {
  s21_decimal a = decimal_create (3, 0, 0, 0);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  int result = s21_is_greater(a, b);
  ck_assert_int_eq(result, FALSE);
}

void test_s21_is_greater_3 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  int result = s21_is_greater(a, b);
  ck_assert_int_eq(result, FALSE);
}

void test_s21_is_greater_4 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0x80000000);
  s21_decimal b = decimal_create (3, 0, 0, 0);
  int result = s21_is_greater(a, b);
  ck_assert_int_eq(result, FALSE);
}

void test_s21_is_greater_5 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (3, 0, 0, 0x80000000);
  int result = s21_is_greater(a, b);
  ck_assert_int_eq(result, TRUE);
}

START_TEST(testing_is_greater) {
    test_s21_is_greater_1();
    test_s21_is_greater_2();
    test_s21_is_greater_3();
    test_s21_is_greater_4();
    test_s21_is_greater_5();
}
END_TEST

void test_s21_is_greater_or_equal_1 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  int result = s21_is_greater_or_equal(a, b);
  ck_assert_int_eq(result, TRUE);
}

void test_s21_is_greater_or_equal_2 (void) {
  s21_decimal a = decimal_create (6, 0, 0, 0);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  int result = s21_is_greater_or_equal(a, b);
  ck_assert_int_eq(result, TRUE);
}

void test_s21_is_greater_or_equal_3 (void) {
  s21_decimal a = decimal_create (4, 0, 0, 0);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  int result = s21_is_greater_or_equal(a, b);
  ck_assert_int_eq(result, FALSE);
}

void test_s21_is_greater_or_equal_4 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0x80000000);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  int result = s21_is_greater_or_equal(a, b);
  ck_assert_int_eq(result, FALSE);
}

void test_s21_is_greater_or_equal_5 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (5, 0, 0, 0x80000000);
  int result = s21_is_greater_or_equal(a, b);
  ck_assert_int_eq(result, TRUE);
}

START_TEST(testing_is_greater_or_equal) {
    test_s21_is_greater_or_equal_1();
    test_s21_is_greater_or_equal_2();
    test_s21_is_greater_or_equal_3();
    test_s21_is_greater_or_equal_4();
    test_s21_is_greater_or_equal_5();
}
END_TEST

void test_s21_is_equal_1 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  int result = s21_is_equal(a, b);
  ck_assert_int_eq(result, TRUE);
}

void test_s21_is_equal_2 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (3, 0, 0, 0);
  int result = s21_is_equal(a, b);
  ck_assert_int_eq(result, FALSE);
}

void test_s21_is_equal_3 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0x80000000);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  int result = s21_is_equal(a, b);
  ck_assert_int_eq(result, FALSE);
}

void test_s21_is_equal_4 (void) {
  s21_decimal a = decimal_create (0, 0, 0, 0);
  s21_decimal b = decimal_create (0, 0, 0, 0x80000000);
  int result = s21_is_equal(a, b);
  ck_assert_int_eq(result, FALSE);
}


void test_s21_is_equal_5 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  a.fields.exponent = 2;
  b.fields.exponent = 3;
  int result = s21_is_equal(a, b);
  ck_assert_int_eq(result, FALSE);
}

START_TEST(testing_is_equal) {
    test_s21_is_equal_1();
    test_s21_is_equal_2();
    test_s21_is_equal_3();
    test_s21_is_equal_4();
    test_s21_is_equal_5();
}
END_TEST

void test_s21_is_not_equal_1 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (3, 0, 0, 0);
  int result = s21_is_not_equal(a, b);
  ck_assert_int_eq(result, TRUE);
}

void test_s21_is_not_equal_2 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  int result = s21_is_not_equal(a, b);
  ck_assert_int_eq(result, FALSE);
}

void test_s21_is_not_equal_3 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0x80000000);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  int result = s21_is_not_equal(a, b);
  ck_assert_int_eq(result, TRUE);
}

void test_s21_is_not_equal_4 (void) {
  s21_decimal a = decimal_create (0, 0, 0, 0);
  s21_decimal b = decimal_create (0, 0, 0, 0x80000000);
  int result = s21_is_not_equal(a, b);
  ck_assert_int_eq(result, TRUE);
}


void test_s21_is_not_equal_5 (void) {
  s21_decimal a = decimal_create (5, 0, 0, 0);
  s21_decimal b = decimal_create (5, 0, 0, 0);
  a.fields.exponent = 1;
  b.fields.exponent = 2;
  int result = s21_is_not_equal(a, b);
  ck_assert_int_eq(result, TRUE);
}

START_TEST(testing_is_not_equal) {
    test_s21_is_not_equal_1();
    test_s21_is_not_equal_2();
    test_s21_is_not_equal_3();
    test_s21_is_not_equal_4();
    test_s21_is_not_equal_5();
}
END_TEST

TCase *comparision (void) {
    TCase *tc = tcase_create("Comparision testing");
    tcase_add_test(tc, testing_is_less);
    tcase_add_test(tc, testing_is_less_or_equal);
    tcase_add_test(tc, testing_is_greater);
    tcase_add_test(tc, testing_is_greater_or_equal);
    tcase_add_test(tc, testing_is_equal);
    tcase_add_test(tc, testing_is_not_equal);
    return tc;
}
