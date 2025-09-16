#include "s21_decimal.h"
#include "decier.h"

#include <string.h>
#include <limits.h>
#include <stdio.h>

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    if (dst == NULL) {
        return CONVERSION_ERROR;
    }
    memset(dst, 0, sizeof(*dst));
    if (src == 0) {
        return OK;
    }
    if (src < 0) {
        dst->fields.negative = SIGN_BIT_NEGATIVE;
        if (src == INT_MIN) {
            dst->fields.lo32 = (unsigned int)INT_MAX + 1;
        } else {
            dst->fields.lo32 = -src;
        }
    } else {
        dst->fields.lo32 = src;
    }
    return OK;
}