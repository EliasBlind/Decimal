#include "s21_decimal.h"
#include "decier.h"

#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>

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

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    if (dst == NULL) {
        return CALCULATION_ERROR;
    }
    memset(dst, 0, sizeof(*dst));
    if (src < 0) {
        dst->fields.negative = SIGN_BIT_NEGATIVE;
        double buffer = -src;
        memcpy(&buffer, &dst->fields.lo32, sizeof(buffer));
    } else {
        memcpy(&src, &dst->fields.lo32, sizeof(src));
    }
    dst->fields.exponent = pow(2, 16);
    while (dst->fields.lo32 % 10 == 0 || 
        dst->fields.exponent == 0) {
        dst->fields.lo32 /= 10;
        dst->fields.exponent--;
    }
    return OK;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    if (dst == NULL) {
        return CALCULATION_ERROR;
    }
    for (int i = 0; i < src.fields.exponent; i++) {
        s21_truncate(src, &src);
    }
    if (src.fields.mid32 == 0 && src.fields.hi32 == 0) {
        *dst = src.fields.lo32;
        if (src.fields.negative) {
            *dst *= -1;
        }
    } else {
        return CALCULATION_ERROR;
    }
    return OK;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {\
    if (dst == NULL) {
        return CONVERSION_ERROR;
    }
    int bit_to_integer_part = log(src.fields.exponent * 10);
    uint64_t float_is_store;
    const int bit_to_float_part = (sizeof(float) / 2) * 8;
    if (sizeof(uint32_t) * 8 + bit_to_float_part > (uint64_t)bit_to_integer_part) {
        bit_to_integer_part -= sizeof(uint32_t) * 8;
        float_is_store = *((uint64_t *)&src.fields.mid32);
    } else {
        float_is_store = *((uint64_t *)&src.fields.lo32);
    }
    if (bit_to_integer_part <= bit_to_float_part) {
        float_is_store <<= bit_to_float_part - bit_to_integer_part;
    } else {
        float_is_store  >>= bit_to_integer_part - bit_to_float_part;
    }
    *dst = (float)float_is_store;
    return OK;
}

