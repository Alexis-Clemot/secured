/*
** EPITECH PROJECT, 2025
** B-CPE-110-NAN-1-1-secured-alexis.clemot
** File description:
** delete_hashtable
*/

#include "hashtable.h"

static void free_data(data_t *to_free)
{
    if (to_free->next)
        free_data(to_free->next);
    if (to_free) {
        if (to_free->value)
            free(to_free->value);
        free(to_free);
    }
}

void delete_hashtable(hashtable_t *ht)
{
    if (!ht)
        return;
    if (!ht->tables)
        return;
    for (int i = 0; i < ht->len && ht->tables; i++) {
        if (ht->tables[i])
            free_data(ht->tables[i]);
    }
    free(ht->tables);
    free(ht);
}
