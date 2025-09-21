#include "s21_decimal.h"

#include <stdio.h>

int main() {
    s21_decimal test;
    s21_from_int_to_decimal(12, &test);
    printf("num %d\n", test.fields.lo32);
    return 0;
}