#ifndef DECIER_H
#define DECIER_H

#include <stdint.h>

#define S21_DECIMAL_MAX ((s21_decimal){ .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0} })

#define BYTES_OF_NUMBER 3

#define OK 0

// Arithmetic operations
#define NEGATIVE_INFINITY 1
#define INFINITY 2
#define DIVISION_BY_ZERO 3

// Comparision operations
#define FALSE 0
#define TRUE 1

// Converters
#define CONVERSION_ERROR 1

// Other functions
#define CALCULATION_ERROR 1

// Sign bit
#define SIGN_BIT_NEGATIVE 1
#define SIGN_BIT_POSITIVE 0

#endif // DECIER_H
