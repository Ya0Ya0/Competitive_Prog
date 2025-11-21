#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h> // Refactor 2: Added for memcpy and memset
//#include <check.h>

#include "testutil.h"
#include "../datagen/generator.h"
#include "../affinity/memalloc.h"

// Refactor 3: Constants defined
#ifndef CACHE_LINE_SIZE
#define CACHE_LINE_SIZE 64
#endif

#define INCRMOD 100 // Refactor 4: Defined instead of magic number
#define MAX_INT64 INT64_MAX // Refactor 4: defined max int for 64-bit
#define MAX_INT32 INT32_MAX // Refactor 4: defined max int for 32-bit
#define NaN_EXP_MASK (0x7FFL << 52U) // Refactor 4
#define NaN_LOWBIT_CLEAR ~(1L << 52U) // Refactor 4

// Refactor 1: Generic sorting check function
typedef int (*compare_func_t)(const void *, const void *);

int is_sorted_generic(void *items, uint64_t nitems, size_t size, compare_func_t cmp) {
    unsigned char *array = (unsigned char *)items;
    for (uint64_t i = 1; i < nitems; i++) {
        if (cmp(array + (i - 1) * size, array + i * size) > 0) {
            return 0; // Not sorted
        }
    }
    return 1; // Sorted
}

// Comparator functions
int compare_int64(const void *a, const void *b) {
    return (*(int64_t*)a - *(int64_t*)b);
}

int compare_int32(const void *a, const void *b) {
    return (*(int32_t*)a - *(int32_t*)b);
}

int compare_tuples(const void *a, const void *b) {
    return (((tuple_t*)a)->key - ((tuple_t*)b)->key);
}

// Replaced original functions with calls to is_sorted_generic
int is_sorted_int64(int64_t *items, uint64_t nitems) {
    return is_sorted_generic(items, nitems, sizeof(int64_t), compare_int64);
}

int is_sorted_int32(int32_t *items, uint64_t nitems) {
    return is_sorted_generic(items, nitems, sizeof(int32_t), compare_int32);
}

int is_sorted_tuples(tuple_t *items, uint64_t nitems) {
    return is_sorted_generic(items, nitems, sizeof(tuple_t), compare_tuples);
}

// Refactor 5: Generic random array generation function
void *generate_random_array(size_t num, size_t size, int ordered, int max_value, int incrmod) {
    char *array = (char *)malloc(size * num);
    int start = 1 + rand() % incrmod;

    for (size_t i = 0; i < num; i++) {
        if (ordered) {
            memcpy(array + i * size, &start, size); // Refactor 2: Use memcpy
            start += (rand() % incrmod);
        } else {
            int random_value = rand() % max_value;
            memcpy(array + i * size, &random_value, size); // Refactor 2: Use memcpy
        }
    }
    return array;
}

// Replaced specific generator calls with generate_random_array
int64_t *generate_rand_int64(int num) {
    return (int64_t *)generate_random_array(num, sizeof(int64_t), 0, MAX_INT64, INCRMOD);
}

int32_t *generate_rand_int32(int num) {
    return (int32_t *)generate_random_array(num, sizeof(int32_t), 0, MAX_INT32, INCRMOD);
}

tuple_t *generate_rand_tuples(int num) {
    tuple_t *items = (tuple_t*)malloc_aligned(sizeof(tuple_t) * num);
    uint64_t i;
    for (i = 0; i < num; i++) {
        items[i].key = (i + 1);
    }
    knuth_shuffle(items); // Assuming knuth_shuffle is somewhere in your included headers
    return items;
}

int64_t *generate_rand_ordered_int64(int num) {
    return (int64_t *)generate_random_array(num, sizeof(int64_t), 1, MAX_INT64, INCRMOD);
}

int32_t *generate_rand_ordered_int32(int num) {
    return (int32_t *)generate_random_array(num, sizeof(int32_t), 1, MAX_INT32, INCRMOD);
}

tuple_t *generate_rand_ordered_tuples(int num) {
    tuple_t *array = (tuple_t *)malloc(sizeof(tuple_t) * num);
    intkey_t startA = 1 + rand() % INCRMOD;
    for (int j = 0; j < num; j++) {
        array[j].key = startA;
        if (startA < MAX_INT32) {
            startA += rand() % INCRMOD;
        }
    }
    return array;
}