#include "s21_decimal.h"
#include "arithmetic_96.h"

#include "decier.h"
#include <stdio.h>

void test_add_96() {
    s21_decimal src = {0};
    s21_decimal dst = {0};
    s21_decimal result = {0};

    // Test case 1: Simple addition
    src.bits[0] = 10;
    dst.bits[0] = 20;
    add_96(src, dst, &result);
    if (result.bits[0] == 30) {
        printf("test_add_96 case 1 passed\n");
    } else {
        printf("test_add_96 case 1 failed\n");
    }

    // Test case 2: Adding zero
    src.bits[0] = 10;
    dst.bits[0] = 0;
    add_96(src, dst, &result);
    if (result.bits[0] == 10) {
        printf("test_add_96 case 2 passed\n");
    } else {
        printf("test_add_96 case 2 failed\n");
    }

    // Test case 3: Adding to zero
    src.bits[0] = 0;
    dst.bits[0] = 20;
    add_96(src, dst, &result);
    if (result.bits[0] == 20) {
        printf("test_add_96 case 3 passed\n");
    } else {
        printf("test_add_96 case 3 failed\n");
    }

    // Test case 4: Adding negative numbers
    src.bits[0] = -10;
    dst.bits[0] = -20;
    add_96(src, dst, &result);
    if ((int64_t)result.bits[0] == (uint32_t)-30) {
        printf("test_add_96 case 4 passed\n");
    } else {
        printf("test_add_96 case 4 failed\n");
    }

    // Test case 5: Adding positive and negative numbers
    src.bits[0] = 10;
    dst.bits[0] = -20;
    add_96(src, dst, &result);
    if (result.bits[0] == (uint32_t)-10) {
        printf("test_add_96 case 5 passed\n");
    } else {
        printf("test_add_96 case 5 failed\n");
    }
}


int main() {
    s21_decimal val;
    s21_from_int_to_decimal(1234, &val);
    val.fields.mid32 = 1;
    int64_t test = *((int64_t *)val.bits);
    printf("%ld\n", test);
    printf("Bytes : \n");
    for(int i = 0; i < 3; i++) {
        printf("%d) %d\n", i, val.bits[i]);
    }

    // Call the test_add_96 function
    test_add_96();

    return 0;
}
