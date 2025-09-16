#include "s21_decimal.h"
#include "decier.h"
#include "comparision_96.h"

#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef TEST
    #define CHECK_NULL(ptr) \
        do { \
            if ((ptr) == NULL) { \
                LOG_ERROR("Null pointer"); \
            } \
        } while (0)
#else // TEST
    #define CHECK_NULL(ptr)
#endif // TEST

int add_96(s21_decimal src, s21_decimal dst, s21_decimal *result) {
    CHECK_NULL(result);

    // Handle edge cases
    if (is_equal_96(src, (s21_decimal){0, 0, 0, 0})) {
        *result = dst;
        return OK;
    }
    if (is_equal_96(dst, (s21_decimal){0, 0, 0, 0})) {
        *result = src;
        return OK;
    }

    // Implementation of the add_96 function
    // This is a placeholder for the actual implementation
    // You should replace this with the actual logic for adding two s21_decimal values
    *((uint64_t *)(&result->fields.lo32)) = (uint64_t)src.fields.lo32 + (uint64_t)dst.fields.lo32;
    *((uint64_t *)(&result->fields.mid32)) = (uint64_t)src.fields.mid32 + (uint64_t)dst.fields.mid32;
    if (is_equal_96(*result, S21_DECIMAL_MAX) || 
        is_less_96(*result, src) ||
        is_less_96(*result, dst)) {
        return INFINITY;
    }
    return OK;
}

/*

int sub_96(s21_decimal *src, int32_t dst) {
    CHECK_NULL(src);
    
}

int mul_96(s21_decimal *src, int32_t dst) {
    CHECK_NULL(src);

}

int div_96(s21_decimal *src, int32_t dst) {
    CHECK_NULL(src);
    
}
*/