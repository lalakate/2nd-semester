#ifndef LAB8_HASH_H
#define LAB8_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bucket {
    size_t hash;
    char *key, *value;
    struct bucket *next;
} bucket;

typedef struct hashmap {
    bucket **buckets;
    unsigned int size, capacity;
} hashmap;

unsigned int hash_create(char *);

unsigned int position(size_t, unsigned int);

void find_in_map(hashmap *, char *);

bucket *find_bucket(hashmap *, char *);

void map_input(hashmap *, char *, char *);

void increase_capacity(hashmap *);

void delete_in_map(hashmap *, char *);

void get_from_file(FILE *, hashmap *, unsigned int);

void task1(FILE *, hashmap *);

void task2(hashmap *);

void task3(hashmap *);

void task4(hashmap *);

void dfs(hashmap *map, bucket *head);

void free_map(hashmap *map);

#endif //LAB8_HASH_H
