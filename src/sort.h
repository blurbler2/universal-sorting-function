#ifndef __SORT_H
#define __SORT_H

#include <stddef.h>  // für size_t

typedef int (*compare_func)(const void*, const void*);

// Standard-Sortierfunktion (-1/0/1 Rückgabewerte)
void insertion_sort_universell(void *base, size_t nitems, size_t size, compare_func compar);

// 1/0-Variante der Sortierfunktion (exakt wie in der Aufgabenstellung)
void insertion_sort_10(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*));

// Standard-Vergleichsfunktionen (-1/0/1)
int compare_int_asc(const void* a, const void* b);
int compare_int_desc(const void* a, const void* b);
int compare_float_asc(const void* a, const void* b);
int compare_float_desc(const void* a, const void* b);

struct Resistance {
    double voltage;
    double current;
};

int compare_resistance_asc(const void* a, const void* b);
int compare_resistance_desc(const void* a, const void* b);

// 1/0-Vergleichsfunktionen (exakt wie in der Aufgabenstellung)
int compare_int_asc_10(const void* a, const void* b);
int compare_float_desc_10(const void* a, const void* b);
int compare_resistance_asc_10(const void* a, const void* b);

#endif
