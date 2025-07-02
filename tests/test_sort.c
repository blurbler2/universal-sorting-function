#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "../src/sort.h"

// Test function for universal sorting
void test_insertion_sort_universell() {
    // Integer Test
    int ints_asc[] = {5, 13, 4, 1, 2, 100, 0, 23, 3, 3, 9, 7};
    size_t ints_size = sizeof(ints_asc) / sizeof(ints_asc[0]);
    insertion_sort_universell(ints_asc, ints_size, sizeof(int), compare_int_asc);
    for (size_t i = 1; i < ints_size; i++) {
        assert(ints_asc[i-1] <= ints_asc[i]); // Simple comparison
    }

    int ints_desc[] = {5, 13, 4, 1, 2, 100, 0, 23, 3, 3, 9, 7};
    insertion_sort_universell(ints_desc, ints_size, sizeof(int), compare_int_desc);
    for (size_t i = 1; i < ints_size; i++) {
        assert(ints_desc[i-1] >= ints_desc[i]); // Simple comparison
    }

    // Float Test
    float floats_asc[] = {5.5f, 3.3f, 4.4f, 1.1f, 2.2f, 100.1f, 0.0f, 3.3f, 3.3f, 3.3f, 9.9f, 7.7f};
    size_t floats_size = sizeof(floats_asc) / sizeof(floats_asc[0]);
    insertion_sort_universell(floats_asc, floats_size, sizeof(float), compare_float_asc);
    for (size_t i = 1; i < floats_size; i++) {
        assert(floats_asc[i-1] <= floats_asc[i]); // Simple comparison
    }

    float floats_desc[] = {5.5f, 3.3f, 4.4f, 1.1f, 2.2f, 100.1f, 0.0f, 3.3f, 3.3f, 3.3f, 9.9f, 7.7f};
    insertion_sort_universell(floats_desc, floats_size, sizeof(float), compare_float_desc);
    for (size_t i = 1; i < floats_size; i++) {
        assert(floats_desc[i-1] >= floats_desc[i]); // Simple comparison
    }

    // Resistance Test
    struct Resistance resistances_asc[] = {
        {1.8, 100}, {1.1, 101}, {2.0, 230}, {3.0, 230},
        {0.5, 50.5}, {1.0, 60}, {2.5, 300}, {1.7, 200},
        {2.2, 150}, {0.9, 40}, {3.3, 400}, {1.2, 120}
    };
    size_t resistances_size = sizeof(resistances_asc) / sizeof(resistances_asc[0]);
    insertion_sort_universell(resistances_asc, resistances_size, sizeof(struct Resistance), compare_resistance_asc);
    for (size_t i = 1; i < resistances_size; i++) {
        double R1 = resistances_asc[i-1].voltage / resistances_asc[i-1].current;
        double R2 = resistances_asc[i].voltage / resistances_asc[i].current;
        assert(R1 <= R2); // Simple comparison
    }

    struct Resistance resistances_desc[] = {
        {1.8, 100}, {1.1, 101}, {2.0, 230}, {3.0, 230},
        {0.5, 50.5}, {1.0, 60}, {2.5, 300}, {1.7, 200},
        {2.2, 150}, {0.9, 40}, {3.3, 400}, {1.2, 120}
    };
    insertion_sort_universell(resistances_desc, resistances_size, sizeof(struct Resistance), compare_resistance_desc);
    for (size_t i = 1; i < resistances_size; i++) {
        double R1 = resistances_desc[i-1].voltage / resistances_desc[i-1].current;
        double R2 = resistances_desc[i].voltage / resistances_desc[i].current;
        assert(R1 >= R2); // Simple comparison
    }

    // Test für Division durch 0
    struct Resistance resistances_with_zero[] = {
        {1.8, 100}, {1.2, 0}, {2.5, 50}, {0.9, 0}, {1.0, 0}, {3.0, 150}, {2.0, 200}, {4.0, 400}, {5.0, 500}
    };
    size_t resistances_with_zero_size = sizeof(resistances_with_zero) / sizeof(resistances_with_zero[0]);

    // Test division by zero - should return error (-1)
    printf("Testing division by zero handling...\n");
    struct Resistance r1 = {1.0, 0}; // current == 0
    struct Resistance r2 = {2.0, 1}; // valid resistance
    int result = compare_resistance_asc(&r1, &r2);
    assert(result == -1); // Should return error for division by zero
    printf("Division by zero test passed: returned -1 as expected\n");

    // Test with valid resistances only
    struct Resistance valid_resistances[] = {
        {1.8, 100}, {2.5, 50}, {3.0, 150}, {2.0, 200}, {4.0, 400}, {5.0, 500}
    };
    size_t valid_size = sizeof(valid_resistances) / sizeof(valid_resistances[0]);

    // Test ascending sort with valid resistances
    insertion_sort_universell(valid_resistances, valid_size, sizeof(struct Resistance), compare_resistance_asc);
    for (size_t i = 1; i < valid_size; i++) {
        double R1 = valid_resistances[i-1].voltage / valid_resistances[i-1].current;
        double R2 = valid_resistances[i].voltage / valid_resistances[i].current;
        assert(R1 <= R2);
    }

    // Test descending sort with valid resistances
    insertion_sort_universell(valid_resistances, valid_size, sizeof(struct Resistance), compare_resistance_desc);
    for (size_t i = 1; i < valid_size; i++) {
        double R1 = valid_resistances[i-1].voltage / valid_resistances[i-1].current;
        double R2 = valid_resistances[i].voltage / valid_resistances[i].current;
        assert(R1 >= R2);
    }

    printf("All tests passed successfully.\n");
} 