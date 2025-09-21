#include <check.h>

TCase *converters() {
    TCase *tc = tcase_create("Converters testing");
    tcase_add_test(tc, testing_from_int_to_decimal);
    tcase_add_test(tc, testing_from_float_to_decimal);
    tcase_add_test(tc, testing_from_decimal_to_int);
    tcase_add_test(tc, testing_from_decimal_to_float);
    return tc;
}

START_TEST(testing_from_int_to_decimal) {

}

START_TEST(testing_from_float_to_decimal) {

}

START_TEST(testing_from_decimal_to_int) {

}

START_TEST(testing_from_decimal_to_float) {

}
