/*
** EPITECH PROJECT, 2025
** B-CPE-110-NAN-1-1-secured-alexis.clemot
** File description:
** ht_delete
*/

#include "hashtable.h"

static bool find_element(data_t **find, int key, data_t **prev)
{
    while ((*find)) {
        if (key == (*find)->key)
            return true;
        (*prev) = (*find);
        (*find) = (*find)->next;
    }
    return false;
}

int ht_delete(hashtable_t *ht, char *key)
{
    data_t *prev = NULL;
    data_t *data;
    int hash_code;
    int id_tables;

    if (!ht || !key)
        return 84;
    if (!ht->tables)
        return 84;
    hash_code = ht->hash(key, ht->len);
    if (hash_code == 84)
        return 84;
    id_tables = hash_code % ht->len;
    if (id_tables < 0)
        id_tables *= -1;
    data = ht->tables[id_tables];
    if (find_element(&data, hash_code, &prev))
        return sup_data(data, prev, ht, id_tables);
    return 84;
}
