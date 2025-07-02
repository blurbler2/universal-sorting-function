#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <stdint.h>
#include "../src/sort.h"

// ============================================================================
// 1. UNIT TESTS FÜR VERGLEICHSFUNKTIONEN
// ============================================================================

void test_compare_int_asc() {
    printf("Testing compare_int_asc...\n");
    
    int a = 5, b = 10;
    assert(compare_int_asc(&a, &b) == -1); // 5 < 10, should return -1
    assert(compare_int_asc(&b, &a) == 1);  // 10 > 5, should return 1
    assert(compare_int_asc(&a, &a) == 0);  // 5 == 5, should return 0
    
    // Test edge cases
    int min_val = INT_MIN, max_val = INT_MAX, zero = 0;
    assert(compare_int_asc(&min_val, &max_val) == -1);
    assert(compare_int_asc(&max_val, &min_val) == 1);
    assert(compare_int_asc(&zero, &min_val) == 1);
    assert(compare_int_asc(&max_val, &zero) == 1);
    
    printf("compare_int_asc tests passed!\n");
}

void test_compare_int_desc() {
    printf("Testing compare_int_desc...\n");
    
    int a = 5, b = 10;
    assert(compare_int_desc(&a, &b) == 1);  // 5 < 10, should return 1 (descending)
    assert(compare_int_desc(&b, &a) == -1); // 10 > 5, should return -1 (descending)
    assert(compare_int_desc(&a, &a) == 0);  // 5 == 5, should return 0
    
    printf("compare_int_desc tests passed!\n");
}

void test_compare_float_asc() {
    printf("Testing compare_float_asc...\n");
    
    float a = 5.5f, b = 10.5f;
    assert(compare_float_asc(&a, &b) == -1); // 5.5 < 10.5, should return -1
    assert(compare_float_asc(&b, &a) == 1);  // 10.5 > 5.5, should return 1
    assert(compare_float_asc(&a, &a) == 0);  // 5.5 == 5.5, should return 0
    
    // Test edge cases
    float min_val = -FLT_MAX, max_val = FLT_MAX, zero = 0.0f, inf_val = INFINITY;
    assert(compare_float_asc(&min_val, &max_val) == -1);
    assert(compare_float_asc(&max_val, &min_val) == 1);
    assert(compare_float_asc(&zero, &min_val) == 1);
    assert(compare_float_asc(&max_val, &zero) == 1);
    
    printf("compare_float_asc tests passed!\n");
}

void test_compare_float_desc() {
    printf("Testing compare_float_desc...\n");
    
    float a = 5.5f, b = 10.5f;
    assert(compare_float_desc(&a, &b) == 1);  // 5.5 < 10.5, should return 1 (descending)
    assert(compare_float_desc(&b, &a) == -1); // 10.5 > 5.5, should return -1 (descending)
    assert(compare_float_desc(&a, &a) == 0);  // 5.5 == 5.5, should return 0
    
    printf("compare_float_desc tests passed!\n");
}

void test_compare_resistance_asc() {
    printf("Testing compare_resistance_asc...\n");
    
    // Test normal cases
    struct Resistance r1 = {10.0, 2.0}; // R = 5.0
    struct Resistance r2 = {20.0, 2.0}; // R = 10.0
    assert(compare_resistance_asc(&r1, &r2) == -1); // 5.0 < 10.0, should return -1
    assert(compare_resistance_asc(&r2, &r1) == 1);  // 10.0 > 5.0, should return 1
    assert(compare_resistance_asc(&r1, &r1) == 0);  // 5.0 == 5.0, should return 0
    
    // Test edge cases - current = 0 (should return -1)
    struct Resistance r_zero_current = {10.0, 0.0};
    assert(compare_resistance_asc(&r_zero_current, &r1) == -1);
    assert(compare_resistance_asc(&r1, &r_zero_current) == -1);
    
    // Test voltage = 0 (short circuit)
    struct Resistance r_zero_voltage = {0.0, 2.0}; // R = 0.0
    assert(compare_resistance_asc(&r_zero_voltage, &r1) == -1); // 0.0 < 5.0
    assert(compare_resistance_asc(&r1, &r_zero_voltage) == 1);  // 5.0 > 0.0
    
    // Test both zero
    struct Resistance r_both_zero = {0.0, 0.0};
    assert(compare_resistance_asc(&r_both_zero, &r1) == -1);
    
    printf("compare_resistance_asc tests passed!\n");
}

void test_compare_resistance_desc() {
    printf("Testing compare_resistance_desc...\n");
    
    // Test normal cases
    struct Resistance r1 = {10.0, 2.0}; // R = 5.0
    struct Resistance r2 = {20.0, 2.0}; // R = 10.0
    assert(compare_resistance_desc(&r1, &r2) == 1);  // 5.0 < 10.0, should return 1 (descending)
    assert(compare_resistance_desc(&r2, &r1) == -1); // 10.0 > 5.0, should return -1 (descending)
    
    // Test edge cases - current = 0 (should return -1)
    struct Resistance r_zero_current = {10.0, 0.0};
    assert(compare_resistance_desc(&r_zero_current, &r1) == -1);
    
    printf("compare_resistance_desc tests passed!\n");
}

// ============================================================================
// 2. INTEGRATION TESTS FÜR SORTIERFUNKTION
// ============================================================================

void test_sort_empty_array() {
    printf("Testing sort with empty array...\n");
    
    int empty_array[] = {};
    insertion_sort_universell(empty_array, 0, sizeof(int), compare_int_asc);
    // Should not crash
    printf("Empty array test passed!\n");
}

void test_sort_single_element() {
    printf("Testing sort with single element...\n");
    
    int single_element[] = {42};
    insertion_sort_universell(single_element, 1, sizeof(int), compare_int_asc);
    assert(single_element[0] == 42);
    
    float single_float[] = {3.14f};
    insertion_sort_universell(single_float, 1, sizeof(float), compare_float_asc);
    assert(single_float[0] == 3.14f);
    
    printf("Single element test passed!\n");
}

void test_sort_already_sorted() {
    printf("Testing sort with already sorted array...\n");
    
    int sorted_asc[] = {1, 2, 3, 4, 5};
    int expected_asc[] = {1, 2, 3, 4, 5};
    size_t size = 5;
    
    insertion_sort_universell(sorted_asc, size, sizeof(int), compare_int_asc);
    for (size_t i = 0; i < size; i++) {
        assert(sorted_asc[i] == expected_asc[i]);
    }
    
    printf("Already sorted test passed!\n");
}

void test_sort_reverse_sorted() {
    printf("Testing sort with reverse sorted array...\n");
    
    int reverse_sorted[] = {5, 4, 3, 2, 1};
    int expected_asc[] = {1, 2, 3, 4, 5};
    size_t size = 5;
    
    insertion_sort_universell(reverse_sorted, size, sizeof(int), compare_int_asc);
    for (size_t i = 0; i < size; i++) {
        assert(reverse_sorted[i] == expected_asc[i]);
    }
    
    printf("Reverse sorted test passed!\n");
}

void test_sort_with_duplicates() {
    printf("Testing sort with duplicates...\n");
    
    int with_duplicates[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    size_t size = 11;
    
    insertion_sort_universell(with_duplicates, size, sizeof(int), compare_int_asc);
    for (size_t i = 1; i < size; i++) {
        assert(with_duplicates[i-1] <= with_duplicates[i]);
    }
    
    printf("Duplicates test passed!\n");
}

void test_sort_large_array() {
    printf("Testing sort with large array...\n");
    
    int large_array[1000];
    for (int i = 0; i < 1000; i++) {
        large_array[i] = 999 - i; // Reverse order
    }
    
    insertion_sort_universell(large_array, 1000, sizeof(int), compare_int_asc);
    for (int i = 1; i < 1000; i++) {
        assert(large_array[i-1] <= large_array[i]);
    }
    
    printf("Large array test passed!\n");
}

// ============================================================================
// 3. SPEZIELLE TESTS FÜR WIDERSTÄNDE
// ============================================================================

void test_resistance_zero_current() {
    printf("Testing resistance with zero current...\n");
    
    struct Resistance resistances[] = {
        {1.8, 100}, {1.2, 0}, {2.5, 50}, {0.9, 0}, {1.0, 0}, {3.0, 150}
    };
    size_t size = 6;
    
    // Test ascending sort - zero current elements should be at the end
    insertion_sort_universell(resistances, size, sizeof(struct Resistance), compare_resistance_asc);
    
    // Find where finite resistances start
    size_t finite_start = size;
    for (size_t i = 0; i < size; i++) {
        if (finite_start == size && resistances[i].current != 0) {
            finite_start = i;
        }
    }
    
    // All elements before finite_start should have current == 0
    for (size_t i = 0; i < finite_start; i++) {
        assert(resistances[i].current == 0);
    }
    
    // All elements from finite_start to end should be sorted ascending by resistance
    if (finite_start < size - 1) {
        for (size_t i = finite_start + 1; i < size; i++) {
            if (resistances[i-1].current != 0 && resistances[i].current != 0) {
                double R1 = resistances[i-1].voltage / resistances[i-1].current;
                double R2 = resistances[i].voltage / resistances[i].current;
                assert(R1 <= R2);
            }
        }
    }
    
    printf("Zero current test passed!\n");
}

void test_resistance_zero_voltage() {
    printf("Testing resistance with zero voltage...\n");
    
    struct Resistance resistances[] = {
        {1.8, 100}, {0.0, 50}, {2.5, 50}, {0.0, 100}, {3.0, 150}
    };
    size_t size = 5;
    
    // Test ascending sort - zero voltage elements should be at the beginning
    insertion_sort_universell(resistances, size, sizeof(struct Resistance), compare_resistance_asc);
    
    // Find where non-zero resistances start
    size_t non_zero_start = size;
    for (size_t i = 0; i < size; i++) {
        if (non_zero_start == size && resistances[i].voltage != 0) {
            non_zero_start = i;
        }
    }
    
    // All elements before non_zero_start should have voltage == 0
    for (size_t i = 0; i < non_zero_start; i++) {
        assert(resistances[i].voltage == 0);
    }
    
    printf("Zero voltage test passed!\n");
}

void test_resistance_both_zero() {
    printf("Testing resistance with both voltage and current zero...\n");
    
    struct Resistance r1 = {0.0, 0.0};
    struct Resistance r2 = {1.0, 1.0};
    
    // Both should return -1 (error)
    assert(compare_resistance_asc(&r1, &r2) == -1);
    assert(compare_resistance_asc(&r2, &r1) == -1);
    assert(compare_resistance_desc(&r1, &r2) == -1);
    assert(compare_resistance_desc(&r2, &r1) == -1);
    
    printf("Both zero test passed!\n");
}

// ============================================================================
// 4. ROBUSTHEITSTESTS
// ============================================================================

void test_null_pointer_handling() {
    printf("Testing null pointer handling...\n");
    
    // Note: These tests might cause segmentation faults in the current implementation
    // In a production environment, the functions should check for null pointers
    
    int valid_array[] = {1, 2, 3};
    
    // Test with null base pointer (this might crash - that's expected for now)
    // insertion_sort_universell(NULL, 3, sizeof(int), compare_int_asc);
    
    // Test with null comparison function (this might crash - that's expected for now)
    // insertion_sort_universell(valid_array, 3, sizeof(int), NULL);
    
    printf("Null pointer test completed (crashes expected in current implementation)\n");
}

void test_invalid_size_handling() {
    printf("Testing invalid size handling...\n");
    
    int valid_array[] = {1, 2, 3};
    
    // Test with zero element size
    insertion_sort_universell(valid_array, 3, 0, compare_int_asc);
    // Should not crash, but might not work correctly
    
    // Test with very large element size
    insertion_sort_universell(valid_array, 3, SIZE_MAX, compare_int_asc);
    // Should not crash, but might not work correctly
    
    printf("Invalid size test completed\n");
}

// ============================================================================
// 5. PERFORMANCE TESTS (Optional)
// ============================================================================

void test_performance_different_sizes() {
    printf("Testing performance with different array sizes...\n");
    
    const int sizes[] = {10, 100, 1000, 10000};
    const int num_sizes = 4;
    
    for (int s = 0; s < num_sizes; s++) {
        int size = sizes[s];
        int* array = malloc(size * sizeof(int));
        
        // Fill with reverse order (worst case for insertion sort)
        for (int i = 0; i < size; i++) {
            array[i] = size - i;
        }
        
        // Sort and verify
        insertion_sort_universell(array, size, sizeof(int), compare_int_asc);
        for (int i = 1; i < size; i++) {
            assert(array[i-1] <= array[i]);
        }
        
        free(array);
        printf("  Size %d: OK\n", size);
    }
    
    printf("Performance test passed!\n");
}

void test_performance_cases() {
    printf("Testing performance cases...\n");
    
    const int size = 1000;
    int* best_case = malloc(size * sizeof(int));
    int* average_case = malloc(size * sizeof(int));
    int* worst_case = malloc(size * sizeof(int));
    
    // Best case: already sorted
    for (int i = 0; i < size; i++) {
        best_case[i] = i;
    }
    
    // Average case: random order
    for (int i = 0; i < size; i++) {
        average_case[i] = (i * 7) % size; // Simple pseudo-random
    }
    
    // Worst case: reverse sorted
    for (int i = 0; i < size; i++) {
        worst_case[i] = size - i;
    }
    
    // Sort all cases
    insertion_sort_universell(best_case, size, sizeof(int), compare_int_asc);
    insertion_sort_universell(average_case, size, sizeof(int), compare_int_asc);
    insertion_sort_universell(worst_case, size, sizeof(int), compare_int_asc);
    
    // Verify all are sorted
    for (int i = 1; i < size; i++) {
        assert(best_case[i-1] <= best_case[i]);
        assert(average_case[i-1] <= average_case[i]);
        assert(worst_case[i-1] <= worst_case[i]);
    }
    
    free(best_case);
    free(average_case);
    free(worst_case);
    
    printf("Performance cases test passed!\n");
}

// ============================================================================
// MAIN TEST FUNCTION (Legacy - kept for compatibility)
// ============================================================================

void test_insertion_sort_universell() {
    printf("Running legacy comprehensive test...\n");
    
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

    printf("Legacy comprehensive test passed!\n");
} 