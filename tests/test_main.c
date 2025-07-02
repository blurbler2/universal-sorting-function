#include <stdio.h>
#include "test_sort.h"

int main() {
    printf("Running universal sorting function tests...\n");
    printf("==========================================\n");
    
    test_insertion_sort_universell();
    
    printf("==========================================\n");
    printf("All tests completed successfully!\n");
    return 0;
} 