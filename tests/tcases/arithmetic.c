#include <check.h>

TCase *arithmetic()
{
    TCase *tc = tcase_create("Arithmetic testing");
    tcase_add_test(tc, testing_add);
    tcase_add_test(tc, testing_sub);
    tcase_add_test(tc, testing_mul);
    tcase_add_test(tc, testing_div);
    return tc;
}

START_TEST(testing_add)
{
}

START_TEST(testing_sub)
{
}

START_TEST(testing_mul)
{
}

START_TEST(testing_div)
{
}
