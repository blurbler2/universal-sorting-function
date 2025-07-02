#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "../src/sort.h"

void print_int_array(const char* text, int *arr, size_t size) {
    printf("%-35s[", text);
    for (size_t i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void print_float_array(const char* text, float *arr, size_t size) {
    printf("%-40s[ ", text);
    for (size_t i = 0; i < size; i++) {
        printf("%.2f", arr[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

void print_resistance_array(const char* text, struct Resistance *arr, size_t size) {
    printf("%s\n[\n", text);
    for (size_t i = 0; i < size; i++) {
        if (arr[i].current == 0) {
            printf("\tFehler: Strom darf nicht 0 sein - Division durch Null (V=%.2f, I=%.2f)", arr[i].voltage, arr[i].current);
        } else if (arr[i].voltage == 0) {
            printf("\tKurzschluss - Spannung ist 0 (V=%.2f, I=%.2f)", arr[i].voltage, arr[i].current);
        } else {
            double R = arr[i].voltage / arr[i].current;
            printf("\tR=%.3f (V=%.2f, I=%.2f)", R, arr[i].voltage, arr[i].current);
        }
        if (i != size - 1) {
            printf(", \n");
        } else {
            printf("\n");
        }
    }
    printf("];\n");
}

int main() {    
    int ints[] = {5,13,4,1,2, 100,0,23,3,3, 9, 7};
    size_t ints_size = sizeof(ints) / sizeof(ints[0]);

    float floats[] = {5.5f, 3.3f, 4.4f, 1.1f, 2.2f, 100.1f, 0.0f, 3.3f, 3.3f, 3.3f, 9.9f, 7.7f};
    size_t floats_size = sizeof(floats) / sizeof(floats[0]);

    struct Resistance resistances[] = {
        {1.8, 100},
        {1.1, 100},
        {2.0, 230},
        {3.0, 230},
        {0.5, 50},
        {1.0, 60},
        {2.5, 300},
        {1.7, 200},
        {2.2, 150},
        {0.9, 40},
        {3.3, 400},
        {1.2, 120},
        {0, 1.5},   // 0/0 = NaN, should be sorted last
        {1.5, 0}
    };
    size_t resistances_size = sizeof(resistances)/sizeof(resistances[0]);

    // Integer
    print_int_array("Ints vor Sortierung: ", ints, ints_size);

    insertion_sort_universell(ints, ints_size, sizeof(int), compare_int_asc);
    print_int_array("Ints nach Sortierung aufsteigend: ", ints, ints_size);

    insertion_sort_universell(ints, ints_size, sizeof(int), compare_int_desc);
    print_int_array("Ints nach Sortierung absteigend: ", ints, ints_size);

    // Float
    print_float_array("\nFloats vor Sortierung: ", floats, floats_size);

    insertion_sort_universell(floats, floats_size, sizeof(float), compare_float_asc);
    print_float_array("Floats nach Sortierung aufsteigend: ", floats, floats_size);

    insertion_sort_universell(floats, floats_size, sizeof(float), compare_float_desc);
    print_float_array("Floats nach Sortierung absteigend: ", floats, floats_size);

    // Resistance
    print_resistance_array("\nWiderstände vor Sortierung :", resistances, resistances_size);

    insertion_sort_universell(resistances, resistances_size, sizeof(struct Resistance), compare_resistance_asc);

    print_resistance_array("Widerstände nach Sortierung aufsteigend (nach R = V/I): ", resistances, resistances_size);
    insertion_sort_universell(resistances, resistances_size, sizeof(struct Resistance), compare_resistance_desc);

    print_resistance_array("Widerstände nach Sortierung absteigend (nach R = V/I): ", resistances, resistances_size);
    
    return 0;
}
