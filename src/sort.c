#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

// Universeller Insertion Sort Algorithmus
void insertion_sort_universell(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)) {
    char *arr = (char *)base;
    char *temp = malloc(size); // temporärer Puffer für ein Element
    if (!temp) return;

    for (size_t i = 1; i < nitems; i++) {
        memcpy(temp, arr + i * size, size); // aktuelles Element in den temporären Puffer kopieren
        ssize_t j = i - 1;

        // Elemente verschieben, bis das richtige Insertionsposition gefunden ist
        while (j >= 0 && compar(arr + j * size, temp) > 0) {
            memcpy(arr + (j + 1) * size, arr + j * size, size);
            j--;
        }
        // Element an die richtige Position verschieben
        memcpy(arr + (j + 1) * size, temp, size);
    }
    free(temp);
}

// Vergleichsfunktionen für int (aufsteigend)
int compare_int_asc(const void* a, const void* b) {
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

// Vergleichsfunktionen für int (absteigend)
int compare_int_desc(const void* a, const void* b) {
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    if (int_a > int_b) return -1;
    if (int_a < int_b) return 1;
    return 0;
}

// Vergleichsfunktionen für float (aufsteigend)
int compare_float_asc(const void* a, const void* b) {
    float float_a = *(float*)a;
    float float_b = *(float*)b;

    if (float_a < float_b) return -1;
    if (float_a > float_b) return 1;
    return 0;
}

// Vergleichsfunktionen für float (absteigend)
int compare_float_desc(const void* a, const void* b) {
    float float_a = *(float*)a;
    float float_b = *(float*)b;

    if (float_a > float_b) return -1;
    if (float_a < float_b) return 1;
    return 0;
}

// Vergleichsfunktionen für Widerstand (aufsteigend)
int compare_resistance_asc(const void* a, const void* b) {
    const struct Resistance* r1 = a;
    const struct Resistance* r2 = b;
    
    // Prüfe auf ungültige Werte
    if (!r1 || !r2) return -1; // Fehler: Null-Pointer
    
    int r1_zero = (r1->current == 0);
    int r2_zero = (r2->current == 0);
    
    if (r1_zero && r2_zero) return 0;
    if (r1_zero) return -1; // r1 infinite, Fehler
    if (r2_zero) return -1; // r2 infinite, Fehler
    
    // Berechne Widerstände nur wenn current != 0
    double R1 = r1->voltage / r1->current;
    double R2 = r2->voltage / r2->current;
    
    if (R1 < R2) return -1;
    if (R1 > R2) return 1;
    // Tie-breaker: voltage
    if (r1->voltage < r2->voltage) return -1;
    if (r1->voltage > r2->voltage) return 1;
    // Tie-breaker: current
    if (r1->current < r2->current) return -1;
    if (r1->current > r2->current) return 1;
    return 0;
}

// Vergleichsfunktionen für Widerstand (absteigend)
int compare_resistance_desc(const void* a, const void* b) {
    const struct Resistance* r1 = a;
    const struct Resistance* r2 = b;
    
    // Prüfe auf ungültige Werte
    if (!r1 || !r2) return -1; // Fehler: Null-Pointer
    
    int r1_zero = (r1->current == 0);
    int r2_zero = (r2->current == 0);
    
    if (r1_zero && r2_zero) return 0;
    if (r1_zero) return -1; // r1 infinite, Fehler
    if (r2_zero) return -1; // r2 infinite, Fehler
    
    // Berechne Widerstände nur wenn current != 0
    double R1 = r1->voltage / r1->current;
    double R2 = r2->voltage / r2->current;
    
    if (R1 > R2) return -1;
    if (R1 < R2) return 1;
    // Tie-breaker: voltage
    if (r1->voltage > r2->voltage) return -1;
    if (r1->voltage < r2->voltage) return 1;
    // Tie-breaker: current
    if (r1->current > r2->current) return -1;
    if (r1->current < r2->current) return 1;
    return 0;
}
