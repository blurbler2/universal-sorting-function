#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

// Universeller Insertion Sort Algorithmus (Standard -1/0/1)
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

// 1/0-Variante der Sortierfunktion (exakt wie in der Aufgabenstellung)
void insertion_sort_10(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)) {
    char *arr = (char *)base;
    char *temp = malloc(size); // temporärer Puffer für ein Element
    if (!temp) return;

    for (size_t i = 1; i < nitems; i++) {
        memcpy(temp, arr + i * size, size); // aktuelles Element in den temporären Puffer kopieren
        ssize_t j = i - 1;

        // Elemente verschieben, bis das richtige Insertionsposition gefunden ist
        // compar gibt 1 zurück, wenn die Relation gilt (p1 R p2)
        while (j >= 0 && compar(arr + j * size, temp)) {
            memcpy(arr + (j + 1) * size, arr + j * size, size);
            j--;
        }
        // Element an die richtige Position verschieben
        memcpy(arr + (j + 1) * size, temp, size);
    }
    free(temp);
}

// Vergleichsfunktionen für int (aufsteigend) - Standard -1/0/1
int compare_int_asc(const void* a, const void* b) {
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

// Vergleichsfunktionen für int (absteigend) - Standard -1/0/1
int compare_int_desc(const void* a, const void* b) {
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    if (int_a > int_b) return -1;
    if (int_a < int_b) return 1;
    return 0;
}

// Vergleichsfunktionen für float (aufsteigend) - Standard -1/0/1
int compare_float_asc(const void* a, const void* b) {
    float float_a = *(float*)a;
    float float_b = *(float*)b;

    if (float_a < float_b) return -1;
    if (float_a > float_b) return 1;
    return 0;
}

// Vergleichsfunktionen für float (absteigend) - Standard -1/0/1
int compare_float_desc(const void* a, const void* b) {
    float float_a = *(float*)a;
    float float_b = *(float*)b;

    if (float_a > float_b) return -1;
    if (float_a < float_b) return 1;
    return 0;
}

// Vergleichsfunktionen für Widerstand (aufsteigend) - Standard -1/0/1
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

// Vergleichsfunktionen für Widerstand (absteigend) - Standard -1/0/1
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

// ============================================================================
// 1/0-VERGLEICHSFUNKTIONEN (exakt wie in der Aufgabenstellung)
// ============================================================================

// int aufsteigend (<) - gibt 1 zurück, wenn Relation gilt, sonst 0
// Für Sortierung: wenn a < b, dann soll a vor b stehen
int compare_int_asc_10(const void* a, const void* b) {
    int int_a = *(const int*)a;
    int int_b = *(const int*)b;
    return int_a > int_b ? 1 : 0; // 1 wenn a > b (dann wird a nach hinten verschoben)
}

// float absteigend (>=) - gibt 1 zurück, wenn Relation gilt, sonst 0
// Für Sortierung: wenn a >= b, dann soll a vor b stehen
int compare_float_desc_10(const void* a, const void* b) {
    float float_a = *(const float*)a;
    float float_b = *(const float*)b;
    return float_a < float_b ? 1 : 0; // 1 wenn a < b (dann wird a nach hinten verschoben)
}

// struct Resistance aufsteigend (R1 < R2) - gibt 1 zurück, wenn Relation gilt, sonst 0
// Für Sortierung: wenn R1 < R2, dann soll R1 vor R2 stehen
int compare_resistance_asc_10(const void* a, const void* b) {
    const struct Resistance* r1 = (const struct Resistance*)a;
    const struct Resistance* r2 = (const struct Resistance*)b;
    
    // Prüfe auf ungültige Werte
    if (!r1 || !r2) return 0; // Fehler: Relation gilt nicht
    
    // Prüfe auf Division durch Null
    if (r1->current == 0 || r2->current == 0) return 0; // Fehler: Relation gilt nicht
    
    // Berechne Widerstände
    double R1 = r1->voltage / r1->current;
    double R2 = r2->voltage / r2->current;
    
    return R1 > R2 ? 1 : 0; // 1 wenn R1 > R2 (dann wird R1 nach hinten verschoben)
}
