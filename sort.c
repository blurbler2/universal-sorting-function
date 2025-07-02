#include "sort.h"
#include <stdlib.h>
#include <string.h>

void insertion_sort_universell(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)) {
    char *arr = (char *)base;
    char *temp = malloc(size);
    if (!temp) return;

    for (size_t i = 1; i < nitems; i++) {
        memcpy(temp, arr + i * size, size);
        ssize_t j = i - 1;

        while (j >= 0 && compar(arr + j * size, temp) > 0) {
            memcpy(arr + (j + 1) * size, arr + j * size, size);
            j--;
        }
        memcpy(arr + (j + 1) * size, temp, size);
    }
    free(temp);
}


int compare_int_asc(const void* a, const void* b) {
    return (*(int*)a) < (*(int*)b);
}

int compare_int_desc(const void* a, const void* b) {
    return (*(int*)a) > (*(int*)b);
}

int compare_float_asc(const void* a, const void* b) {
    return (*(float*)a) < (*(float*)b);
}

int compare_float_desc(const void* a, const void* b) {
    return (*(float*)a) > (*(float*)b);
}

int compare_resistance_asc(const void* a, const void* b) {
    const struct Resistance* r1 = a;
    const struct Resistance* r2 = b;
    double R1 = r1->voltage / r1->current;
    double R2 = r2->voltage / r2->current;
    return R1 < R2;
}

int compare_resistance_desc(const void* a, const void* b) {
    const struct Resistance* r1 = a;
    const struct Resistance* r2 = b;
    double R1 = r1->voltage / r1->current;
    double R2 = r2->voltage / r2->current;
    return R1 > R2;
}
