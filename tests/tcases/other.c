#include <check.h>

TCase *other() {
    TCase *tc = tcase_create("Other testing");
    tcase_add_test(tc, testing_floor);
    tcase_add_test(tc, testing_round);
    tcase_add_test(tc, testing_truncate);
    tcase_add_test(tc, testing_negate);
    return tc;
}

START_TEST(testing_floor) {

}

START_TEST(testing_round) {

}

START_TEST(testing_truncate) {

}

START_TEST(testing_negate) {

}
