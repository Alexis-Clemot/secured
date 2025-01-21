/*
** EPITECH PROJECT, 2025
** B-CPE-110-NAN-1-1-secured-alexis.clemot
** File description:
** ht_insert
*/

#include "hashtable.h"

static int my_strlen(char const *str)
{
    int n = 0;

    while (str[n] != '\0') {
        n++;
    }
    return n;
}

static char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    int i = 0;
    char *allo_memo = malloc(sizeof(char) * (len + 1));

    if (allo_memo == NULL)
        return "X";
    while (i < len) {
        allo_memo[i] = src[i];
        i++;
    }
    allo_memo[i] = '\0';
    return allo_memo;
}

static int sup_if_already_in(hashtable_t *ht, int hash_code, int list_id)
{
    data_t *prev = NULL;
    data_t *data = ht->tables[list_id];

    while (data) {
        if (data->key == hash_code)
            return sup_data(data, prev, ht, list_id);
        prev = data;
        data = data->next;
    }
    return 0;
}

static int add_to_table(hashtable_t *ht, int hash_code,
    int list_id, char *value)
{
    data_t *new_arg = malloc(sizeof(data_t));

    if (!new_arg || hash_code == 84)
        return 84;
    new_arg->key = hash_code;
    new_arg->value = my_strdup(value);
    new_arg->next = ht->tables[list_id];
    ht->tables[list_id] = new_arg;
    return 0;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int hash_code;
    int list_id;

    if (!ht || !key || !value)
        return 84;
    if (!ht->tables)
        return 84;
    hash_code = ht->hash(key, ht->len);
    list_id = hash_code % ht->len;
    if (list_id < 0)
        list_id *= -1;
    sup_if_already_in(ht, hash_code, list_id);
    add_to_table(ht, hash_code, list_id, value);
    return 0;
}
