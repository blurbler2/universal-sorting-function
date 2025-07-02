#ifndef __SORT_H
#define __SORT_H

#include <stddef.h>  // für size_t

typedef int (*compare_func)(const void*, const void*);

void insertion_sort_universell(void *base, size_t nitems, size_t size, compare_func compar);

// Vergleichsfunktionen
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

#endif
