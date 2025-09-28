#include "s21_decimal.h"
#include "decier.h"
#include "comparision_96.h"

// Вырвнивание экспонентыв начале нужно добавить
#define FUNK_BUILDER(FUNC_NAME, FUNC_CHECK, RESULT) \
    int FUNC_NAME(s21_decimal value_1, s21_decimal value_2) { \
        if (value_1.fields.negative == value_2.fields.negative) { \
            if (value_1.fields.exponent == value_2.fields.exponent) { \
                return FUNC_CHECK(value_1, value_2); \
            } \
        } \
        if (value_1.fields.negative) { \
            return RESULT; \
        } \
        return !RESULT; \
    }

FUNK_BUILDER(s21_is_less, is_less_96, TRUE);
FUNK_BUILDER(s21_is_less_or_equal, is_less_or_equal_96, TRUE);
FUNK_BUILDER(s21_is_greater, is_greater_96, FALSE);
FUNK_BUILDER(s21_is_greater_or_equal, is_greater_or_equal_96, FALSE);

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
    return value_1.fields.negative == value_2.fields.negative &&
    value_1.fields.exponent == value_2.fields.exponent ? 
    is_equal_96(value_1, value_2) : FALSE;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
    return value_1.fields.negative == value_2.fields.negative &&
    value_1.fields.exponent == value_2.fields.exponent ?
    is_not_equal_96(value_1, value_2) : TRUE;
}
