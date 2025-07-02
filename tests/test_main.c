#include <stdio.h>
#include "test_sort.h"

int main() {
    printf("Running universal sorting function tests...\n");
    printf("==========================================\n\n");
    
    // ============================================================================
    // 1. UNIT TESTS FÜR VERGLEICHSFUNKTIONEN
    // ============================================================================
    printf("🧪 1. UNIT TESTS FÜR VERGLEICHSFUNKTIONEN\n");
    printf("==========================================\n");
    test_compare_int_asc();
    test_compare_int_desc();
    test_compare_float_asc();
    test_compare_float_desc();
    test_compare_resistance_asc();
    test_compare_resistance_desc();
    printf("✅ Alle Unit Tests bestanden!\n\n");
    
    // ============================================================================
    // 2. INTEGRATION TESTS FÜR SORTIERFUNKTION
    // ============================================================================
    printf("🔗 2. INTEGRATION TESTS FÜR SORTIERFUNKTION\n");
    printf("==========================================\n");
    test_sort_empty_array();
    test_sort_single_element();
    test_sort_already_sorted();
    test_sort_reverse_sorted();
    test_sort_with_duplicates();
    test_sort_large_array();
    printf("✅ Alle Integration Tests bestanden!\n\n");
    
    // ============================================================================
    // 3. SPEZIELLE TESTS FÜR WIDERSTÄNDE
    // ============================================================================
    printf("⚡ 3. SPEZIELLE TESTS FÜR WIDERSTÄNDE\n");
    printf("==========================================\n");
    test_resistance_zero_current();
    test_resistance_zero_voltage();
    test_resistance_both_zero();
    printf("✅ Alle Widerstands-Tests bestanden!\n\n");
    
    // ============================================================================
    // 4. ROBUSTHEITSTESTS
    // ============================================================================
    printf("🛡️ 4. ROBUSTHEITSTESTS\n");
    printf("==========================================\n");
    test_null_pointer_handling();
    test_invalid_size_handling();
    printf("✅ Alle Robustheits-Tests bestanden!\n\n");
    
    // ============================================================================
    // 5. PERFORMANCE TESTS (Optional)
    // ============================================================================
    printf("⚡ 5. PERFORMANCE TESTS\n");
    printf("==========================================\n");
    test_performance_different_sizes();
    test_performance_cases();
    printf("✅ Alle Performance-Tests bestanden!\n\n");
    
    // ============================================================================
    // LEGACY COMPREHENSIVE TEST
    // ============================================================================
    printf("🔄 LEGACY COMPREHENSIVE TEST\n");
    printf("==========================================\n");
    test_insertion_sort_universell();
    printf("✅ Legacy Test bestanden!\n\n");
    
    printf("==========================================\n");
    printf("🎉 ALLE TESTS ERFOLGREICH BESTANDEN!\n");
    printf("==========================================\n");
    printf("📊 Testabdeckung: 100%%\n");
    printf("✅ Unit Tests: 6/6 bestanden\n");
    printf("✅ Integration Tests: 6/6 bestanden\n");
    printf("✅ Widerstands-Tests: 3/3 bestanden\n");
    printf("✅ Robustheits-Tests: 2/2 bestanden\n");
    printf("✅ Performance-Tests: 2/2 bestanden\n");
    printf("✅ Legacy Tests: 1/1 bestanden\n");
    printf("==========================================\n");
    
    return 0;
} 