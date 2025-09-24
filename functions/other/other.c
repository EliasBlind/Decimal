#include "decier.h"
#include "s21_decimal.h"

#include <stdio.h>
#include <string.h>

/*
int s21_truncate(s21_decimal value, s21_decimal *result) {
    if (result == NULL) {
        return CALCULATION_ERROR;
    }
    for (int32_t i = 0; i < value.fields.exponent; i++ ) {
        // minus
    }
    memcpy(result, &value, sizeof(value));
    result->fields.exponent = 0;
     return OK;
}
*/

int s21_negate(s21_decimal value, s21_decimal *result) {
    if (result == NULL) {
        return CALCULATION_ERROR;
    }
    memcpy(result, &value, sizeof(value));
    result->fields.negative = !result->fields.negative;
    return OK;
}
