#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <stdint.h>

/**
 * @brief Structure to represent a decimal number.
 *
 * This union represents a decimal number using a 128-bit structure.
 * The bits array is used to store the 96-bit number and the technical bits.
 */

/// Little-endian 
typedef struct {
    // Number 96 bits
    uint32_t lo32;
    uint32_t mid32;
    uint32_t hi32;
    
    // Technical bits
    uint16_t unused16;
    /// Power of 10 to divide an integer  
    uint8_t exponent;   
    uint8_t unused7 : 7;
    /// 1 - negative, 0 - positive
    uint8_t negative : 1;
} DecimalMap;
    
/// Little-endian 
typedef union {
    DecimalMap fields;
    uint32_t bits[4];
} s21_decimal;

// Arithmetic
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Comparision
int s21_is_less(s21_decimal value_1, s21_decimal value_2); // <
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2); // <=
int s21_is_greater(s21_decimal value_1, s21_decimal value_2); // >
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2); // >=
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);// ==
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2); // !=

// Converters
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Other
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

#endif // S21_DECIMAL_H
