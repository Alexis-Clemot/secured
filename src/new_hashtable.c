/*
** EPITECH PROJECT, 2025
** B-CPE-110-NAN-1-1-secured-alexis.clemot
** File description:
** new_hashtable
*/

#include "hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *hashtable = malloc(sizeof(hashtable_t));

    if (!hashtable || len < 1)
        return NULL;
    hashtable->len = len;
    hashtable->hash = hash;
    hashtable->tables = malloc(sizeof(data_t *) * len);
    if (!hashtable->tables) {
        free(hashtable);
        return NULL;
    }
    for (int i = 0; i < len; i++)
        hashtable->tables[i] = NULL;
    return hashtable;
}
