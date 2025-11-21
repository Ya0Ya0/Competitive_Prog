#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h> // Refactor 2

// Refactor 3 & 4
#define CACHE_LINE_SIZE 64
#define INCRMOD 100
#define MAX_INT64 (~(1LL << 63))
#define MAX_INT32 (~(1 << 31))
#define NAN_EXP_MASK (0x7FFLL << 52U)
#define NAN_LOW_BIT_CLEAR ~(1LL << 52U)

//#include <check.h>

#include "testutil.h"
#include "../datagen/generator.h"
#include "../affinity/memalloc.h"


// Refactor 1
template <typename T>
int is_sorted(T *items, uint64_t nitems, int (*cmp)(const void *, const void *)) {
    if (nitems <= 1) return 1; // Refactor 1: Handle edge case

    for (uint64_t i = 1; i < nitems; i++) {
        if (cmp(&items[i], &items[i - 1]) < 0) {  // Refactor 1:  Use comparison function.
            fprintf(stderr, "[ERROR] item[%" PRIu64 "] is less than item[%" PRIu64 "]\n", i, i - 1); // Refactor 1
            return 0;
        }
    }

    return 1;
}

// Refactor 1
int cmp_int64(const void *a, const void *b) {
    return (*(int64_t *)a - *(int64_t *)b);
}

// Refactor 1
int cmp_int32(const void *a, const void *b) {
    return (*(int32_t *)a - *(int32_t *)b);
}

// Refactor 1
int cmp_tuple(const void *a, const void *b) {
    return (((tuple_t *)a)->key - ((tuple_t *)b)->key);
}


int is_sorted_int64(int64_t *items, uint64_t nitems) { // Refactor 1
    return is_sorted(items, nitems, cmp_int64);      // Refactor 1
}

int is_sorted_int32(int32_t *items, uint64_t nitems) { // Refactor 1
    return is_sorted(items, nitems, cmp_int32);      // Refactor 1
}

int is_sorted_tuples(tuple_t *items, uint64_t nitems) { // Refactor 1
    return is_sorted(items, nitems, cmp_tuple);      // Refactor 1
}


int is_array_equal(int64_t *arr1, int64_t *arr2, uint64_t sz1, uint64_t sz2) {
    if (sz1 != sz2)
        return 0;

    //Refactor 2 & 7
    return memcmp(arr1,arr2, sz1 * sizeof(int64_t)) == 0;
}



// Refactor 5
template <typename T>
T *generate_random_array(int num, bool ordered, T min_val = 0, T max_val = MAX_INT32) {
    T *A = (T *) malloc(sizeof(T) * num); // Refactor 6
    if (!A) { // Refactor 6
        perror("Failed to allocate memory"); // Refactor 6
        return nullptr; // Refactor 6
    }



    if (ordered) { // Refactor 5
        T start = min_val + rand() % INCRMOD; // Refactor 3 & 4
        for (int j = 0; j < num; j++) {
            A[j] = start;
            if (start < max_val) {
                start += rand() % INCRMOD;  // Refactor 3,4
            }
        }
    } else {   // Refactor 5
        for (int j = 0; j < num; j++) {   // Refactor 5
            // generate random number in a portable way
            A[j] = min_val + (T)(((double)rand() / RAND_MAX) * (max_val - min_val)); // Refactor 4 & 7
        }
    }
    return A;
}

int64_t *generate_rand_int64(int num) {   // Refactor 5
    return generate_random_array<int64_t>(num, false, 0, MAX_INT64); // Refactor 4, 5
}

int32_t *generate_rand_int32(int num) {   // Refactor 5
    return generate_random_array<int32_t>(num, false); // Refactor 5
}

tuple_t *generate_rand_tuples(int num) {
    relation_t rel;
    rel.tuples = (tuple_t *) malloc_aligned(sizeof(tuple_t) * num); // Refactor 6
    rel.num_tuples = num;
    if (!rel.tuples) {
        perror("Failed to allocate aligned memory"); // Refactor 6
        return nullptr; // Refactor 6
    }

    for (uint64_t i = 0; i < num; i++) {
        rel.tuples[i].key = (i + 1);
    }

    knuth_shuffle(&rel);

    return rel.tuples;
}


int64_t *generate_rand_ordered_int64(int num) { // Refactor 5
    return generate_random_array<int64_t>(num, true, 0, MAX_INT64); // Refactor 4, 5
}

int32_t *generate_rand_ordered_int32(int num) { // Refactor 5
    return generate_random_array<int32_t>(num, true); // Refactor 5
}


tuple_t *generate_rand_ordered_tuples(int num) { // Refactor 5
    tuple_t *tuples = generate_random_array<tuple_t>(num, true); // Refactor 5
    if (!tuples) { // Refactor 6
         return nullptr; // Refactor 6
    }
    return tuples;
}