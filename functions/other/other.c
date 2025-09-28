#include "s21_decimal.h"
#include "decier.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

void shift_right_n_bits_optimized(s21_decimal *src, unsigned int n) {
    const int word_len = sizeof(uint32_t) * 8;
    if (n >= (sizeof(*src) - sizeof(uint32_t)) * 8) {
        memset(src, 0, sizeof(*src));
        return;
    }
    
    unsigned int element_shift = n / word_len;
    unsigned int bit_shift = n % word_len;
    
    uint32_t temp[3];
    
    temp[0] = (element_shift <= 2) ? ((element_shift <= 1) ?
    src->bits[element_shift] : src->bits[2]) : 0;
    temp[1] = (element_shift <= 1) ? src->bits[element_shift + 1] : 0;
    temp[2] = (element_shift == 0) ? src->bits[2] : 0;
    
    if (bit_shift > 0) {
        uint32_t mask = (1U << bit_shift) - 1;
        src->bits[0] = (temp[0] >> bit_shift) | ((temp[1] & mask) << (word_len - bit_shift));
        src->bits[1] = (temp[1] >> bit_shift) | ((temp[2] & mask) << (word_len - bit_shift));
        src->bits[2] = temp[2] >> bit_shift;
    } else {
        src->bits[0] = temp[0];
        src->bits[1] = temp[1];
        src->bits[2] = temp[2];
    }
}

int s21_negate(s21_decimal value, s21_decimal *result) {
    if (result == NULL) {
        return CALCULATION_ERROR;
    }
    memcpy(result, &value, sizeof(value));
    result->fields.negative = !result->fields.negative;
    return OK;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int status = 1;
  if (result != NULL) {
    s21_truncate(value, result);
    if (value.fields.negative == SIGN_BIT_NEGATIVE) {
        s21_decimal one = decimal_create(1, 0, 0, 0);
        result->fields.negative = SIGN_BIT_NEGATIVE;
        s21_sub(*result, one, result);
    }
    status = 0;
  }
  return status;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
    if (result == NULL) {
        return CALCULATION_ERROR;
    }
    int bit_to_integer_part = (int)log(value.fields.exponent * 10);
    value.fields.exponent = 0;
    shift_right_n_bits_optimized(&value, bit_to_integer_part);
    memcpy(result, &value, sizeof(value));
    return OK;
}

int s21_round(s21_decimal value, s21_decimal *result) {
    if (result == NULL) {
        return CALCULATION_ERROR;
    }
    if (value.fields.exponent == 0) {
        *result = value;
    } else if (value.fields.exponent <= 28) {
        s21_decimal temp = decimal_create(0, 0, 0, 0);
        s21_decimal temp1 = decimal_create(0, 0, 0, 0);
        s21_truncate(value, &temp);
        s21_sub(value, temp, &temp1);
        s21_decimal half = decimal_create(5, 0, 0, 0);
        half.fields.exponent = 1;
        temp1.fields.exponent = value.fields.exponent;
        temp1.fields.negative = SIGN_BIT_POSITIVE;
        s21_decimal one = decimal_create(1, 0, 0, 0);
        if (s21_is_greater_or_equal(temp1, half)) {
            one.fields.exponent = value.fields.exponent;
            s21_add(temp, one, &temp);
        }
        *result = temp;
    } else {
        return CONVERSION_ERROR;
    }
    return OK;
}
