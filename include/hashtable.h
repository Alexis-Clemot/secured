/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H
    #include <stdlib.h>
    #include <stdbool.h>

typedef struct data_s {
    int key;
    char *value;
    struct data_s *next;
} data_t;

typedef struct hashtable_s {
    int len;
    int (*hash)(char *, int);
    data_t **tables;
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

void print_nbr(unsigned long long nb);
int sup_data(data_t *data, data_t *prev, hashtable_t *ht, int i);


#endif /* HASHTABLE_H */
