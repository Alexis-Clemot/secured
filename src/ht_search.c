/*
** EPITECH PROJECT, 2025
** B-CPE-110-NAN-1-1-secured-alexis.clemot
** File description:
** ht_search
*/

#include "hashtable.h"

static bool find_element(data_t **find, int key)
{
    while (*find) {
        if (key == (*find)->key)
            return true;
        (*find) = (*find)->next;
    }
    return false;
}

char *ht_search(hashtable_t *ht, char *key)
{
    data_t *data;
    int hash_code;
    int id_tables;

    if (!ht || !key)
        return NULL;
    if (!ht->tables)
        return NULL;
    hash_code = ht->hash(key, ht->len);
    if (hash_code == 84)
        return NULL;
    id_tables = hash_code % ht->len;
    if (id_tables < 0)
        id_tables *= -1;
    data = ht->tables[id_tables];
    if (find_element(&data, hash_code))
        return data->value;
    return NULL;
}
