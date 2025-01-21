/*
** EPITECH PROJECT, 2025
** B-CPE-110-NAN-1-1-secured-alexis.clemot
** File description:
** sup_data
*/

#include "hashtable.h"

int sup_data(data_t *data, data_t *prev, hashtable_t *ht, int i)
{
    data_t *del = data;

    if (!prev)
        ht->tables[i] = ht->tables[i]->next;
    else
        prev->next = data->next;
    free(del->value);
    free(del);
    return 0;
}
