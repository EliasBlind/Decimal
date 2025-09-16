#include "s21_decimal.h"
#include "decier.h"

#define FUNCS_FOR_EQUAL(FUNC_NAME, OP, LOGIC) \
    int FUNC_NAME(s21_decimal value_1, s21_decimal value_2) { \
        if ( *((uint64_t *)value_1.bits) OP *((uint64_t *)value_2.bits) LOGIC \
            value_1.fields.hi32 OP value_2.fields.hi32 ) { \
            return TRUE; \
        } \
        return FALSE; \
    }

#define FUNCS_FOR_GREATER_OR_LESS(FUNC_NAME, OP) \
    int FUNC_NAME(s21_decimal value_1, s21_decimal value_2) { \
        if ( *((uint64_t *)value_1.bits) OP *((uint64_t *)value_2.bits)) { \
            return TRUE; \
        } else if (value_1.fields.hi32 OP value_2.fields.hi32) { \
            return TRUE; \
        } \
        return FALSE; \
    }

FUNCS_FOR_GREATER_OR_LESS(is_less_96, <);
FUNCS_FOR_GREATER_OR_LESS(is_greater_96, >);

FUNCS_FOR_EQUAL(is_equal_96, ==, &&);
FUNCS_FOR_EQUAL(is_not_equal_96, !=, ||);

int is_less_or_equal_96(s21_decimal value_1, s21_decimal value_2) {
    return is_less_96(value_1, value_2) || is_equal_96(value_1, value_2);
}

int is_greater_or_equal_96(s21_decimal value_1, s21_decimal value_2) {
    return is_greater_96(value_1, value_2) || is_equal_96(value_1, value_2);
}
