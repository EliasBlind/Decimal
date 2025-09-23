#include "s21_decimal.h"
#include "tcases.h"

#include <stdio.h>
#include <check.h>

Suite *init_suite(void)
{
    Suite *suite = suite_create("Decimal testing");

    TCase *test_cases[] = {
        arithmetic(),
        comparision(),
        converters(),
        other(),
    };
    const int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    for (int i = 0; i < num_cases; i++)
    {
        suite_add_tcase(suite, test_cases[i]);
    }
    return suite;
}

int main(void)
{
    Suite *suite = init_suite();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all(suite_runner, CK_NORMAL);
    const int failed_count = srunner_ntests_failed(suite_runner);
    if (failed_count != 0)
    {
        printf("\033[31m");
        printf("Tests failed: %d\n", failed_count);
        return 1;
    }
    printf("All tests passed\n");
    return 0;
}
