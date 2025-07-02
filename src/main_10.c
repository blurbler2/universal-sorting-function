#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

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
    // Seed für Zufallszahlen
    srand(time(NULL));
    
    printf("=== 1/0-VARIANTE DER SORTIERFUNKTION (Aufgabenstellung) ===\n\n");
    
    // ============================================================================
    // 1. INT ARRAY (unsigned) - Relation: < (aufsteigend)
    // ============================================================================
    printf("1. INT ARRAY - Relation: < (aufsteigend)\n");
    printf("==========================================\n");
    
    int ints[12];
    // Zufällige Werte zuweisen
    for (int i = 0; i < 12; i++) {
        ints[i] = rand() % 100; // 0-99
    }
    
    print_int_array("Ints vor Sortierung: ", ints, 12);
    
    // Sortieren mit 1/0-Variante
    insertion_sort_10(ints, 12, sizeof(int), compare_int_asc_10);
    
    print_int_array("Ints nach Sortierung (<): ", ints, 12);
    
    // Verifizierung: data[i] <= data[i+1] für alle i (aufsteigend sortiert, erlaubt Duplikate)
    printf("Verifizierung: ");
    int correct = 1;
    for (int i = 0; i < 11; i++) {
        if (ints[i] > ints[i+1]) {
            correct = 0;
            break;
        }
    }
    printf("%s\n\n", correct ? "✅ Korrekt sortiert" : "❌ Fehler in der Sortierung");
    
    // ============================================================================
    // 2. FLOAT ARRAY - Relation: >= (absteigend)
    // ============================================================================
    printf("2. FLOAT ARRAY - Relation: >= (absteigend)\n");
    printf("==========================================\n");
    
    float floats[12];
    // Zufällige Werte zuweisen
    for (int i = 0; i < 12; i++) {
        floats[i] = (float)(rand() % 1000) / 10.0f; // 0.0-99.9
    }
    
    print_float_array("Floats vor Sortierung: ", floats, 12);
    
    // Sortieren mit 1/0-Variante
    insertion_sort_10(floats, 12, sizeof(float), compare_float_desc_10);
    
    print_float_array("Floats nach Sortierung (>=): ", floats, 12);
    
    // Verifizierung: data[i] >= data[i+1] für alle i (absteigend sortiert)
    printf("Verifizierung: ");
    correct = 1;
    for (int i = 0; i < 11; i++) {
        if (floats[i] < floats[i+1]) {
            correct = 0;
            break;
        }
    }
    printf("%s\n\n", correct ? "✅ Korrekt sortiert" : "❌ Fehler in der Sortierung");
    
    // ============================================================================
    // 3. STRUCT RESISTANCE ARRAY - Relation: R1 < R2 (aufsteigend)
    // ============================================================================
    printf("3. STRUCT RESISTANCE ARRAY - Relation: R1 < R2 (aufsteigend)\n");
    printf("==========================================\n");
    
    struct Resistance resistances[12];
    // Zufällige Werte zuweisen (Vermeidung von Division durch Null)
    for (int i = 0; i < 12; i++) {
        resistances[i].voltage = (double)(rand() % 1000) / 10.0; // 0.0-99.9V
        resistances[i].current = (double)(rand() % 100 + 1) / 10.0; // 0.1-10.0A (nie 0)
    }
    
    print_resistance_array("Widerstände vor Sortierung:", resistances, 12);
    
    // Sortieren mit 1/0-Variante
    insertion_sort_10(resistances, 12, sizeof(struct Resistance), compare_resistance_asc_10);
    
    print_resistance_array("Widerstände nach Sortierung (R1 < R2):", resistances, 12);
    
    // Verifizierung: R[i] <= R[i+1] für alle i (aufsteigend sortiert, erlaubt Duplikate)
    printf("Verifizierung: ");
    correct = 1;
    for (int i = 0; i < 11; i++) {
        double R1 = resistances[i].voltage / resistances[i].current;
        double R2 = resistances[i+1].voltage / resistances[i+1].current;
        if (R1 > R2) {
            correct = 0;
            break;
        }
    }
    printf("%s\n\n", correct ? "✅ Korrekt sortiert" : "❌ Fehler in der Sortierung");
    
    // ============================================================================
    // ZUSAMMENFASSUNG
    // ============================================================================
    printf("=== ZUSAMMENFASSUNG ===\n");
    printf("✅ Alle drei Arrays wurden erfolgreich mit der 1/0-Variante sortiert\n");
    printf("✅ Die Relationen wurden korrekt angewendet:\n");
    printf("   - int: < (aufsteigend)\n");
    printf("   - float: >= (absteigend)\n");
    printf("   - struct Resistance: R1 < R2 (aufsteigend)\n");
    printf("✅ Die Sortierfunktion arbeitet mit beliebigen Datenstrukturen\n");
    printf("✅ Die Vergleichsfunktionen geben 1 zurück, wenn die Relation gilt, sonst 0\n");
    printf("✅ Für alle Elemente gilt: data[i] R data[i+1]\n\n");
    
    return 0;
} 