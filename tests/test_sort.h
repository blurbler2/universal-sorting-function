#ifndef TEST_SORT_H
#define TEST_SORT_H

// ============================================================================
// 1. UNIT TESTS FÜR VERGLEICHSFUNKTIONEN
// ============================================================================
void test_compare_int_asc();
void test_compare_int_desc();
void test_compare_float_asc();
void test_compare_float_desc();
void test_compare_resistance_asc();
void test_compare_resistance_desc();

// ============================================================================
// 2. INTEGRATION TESTS FÜR SORTIERFUNKTION
// ============================================================================
void test_sort_empty_array();
void test_sort_single_element();
void test_sort_already_sorted();
void test_sort_reverse_sorted();
void test_sort_with_duplicates();
void test_sort_large_array();

// ============================================================================
// 3. SPEZIELLE TESTS FÜR WIDERSTÄNDE
// ============================================================================
void test_resistance_zero_current();
void test_resistance_zero_voltage();
void test_resistance_both_zero();

// ============================================================================
// 4. ROBUSTHEITSTESTS
// ============================================================================
void test_null_pointer_handling();
void test_invalid_size_handling();

// ============================================================================
// 5. PERFORMANCE TESTS (Optional)
// ============================================================================
void test_performance_different_sizes();
void test_performance_cases();

// ============================================================================
// MAIN TEST FUNCTION (Legacy - kept for compatibility)
// ============================================================================
void test_insertion_sort_universell();

#endif 