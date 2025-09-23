#include "s21_decimal.h"

#include <check.h>

void eq_decimal(s21_decimal x, s21_decimal y) {
    const int decimal_items = sizeof(s21_decimal) / sizeof(int32_t);
    for (int i = 0; i < decimal_items; i++) {
        ck_assert_int_eq(x.bits[i], y.bits[i]);
    }
}