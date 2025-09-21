#include <check.h>

TCase *comparision() {
    TCase *tc = tcase_create("Comparision testing");
    tcase_add_test(tc, testing_is_less);
    tcase_add_test(tc, testing_is_less_or_equal);
    tcase_add_test(tc, testing_is_greater);
    tcase_add_test(tc, testing_is_greater_or_equal);
    tcase_add_test(tc, testing_is_equal);
    tcase_add_test(tc, testing_is_not_equal);
    return tc;
}

START_TEST(testing_is_less) {

}

START_TEST(testing_is_less_or_equal) {

}

START_TEST(testing_is_greater) {

}

START_TEST(testing_is_greater_or_equal) {

}

START_TEST(testing_is_equal) {

}

START_TEST(testing_is_not_equal) {

}
