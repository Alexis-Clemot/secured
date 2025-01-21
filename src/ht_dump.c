/*
** EPITECH PROJECT, 2025
** B-CPE-110-NAN-1-1-secured-alexis.clemot
** File description:
** ht_dump
*/

#include "hashtable.h"
#include "unistd.h"

static int my_strlen(char const *str)
{
    int n = 0;

    while (str[n] != '\0') {
        n++;
    }
    return n;
}

static void disp_arg(data_t *disp)
{
    while (disp) {
        write(1, "> ", 2);
        print_nbr(disp->key);
        write(1, " - ", 3);
        write(1, disp->value, my_strlen(disp->value));
        write(1, "\n", 1);
        disp = disp->next;
    }
}

void ht_dump(hashtable_t *ht)
{
    if (!ht)
        return;
    if (!ht->tables)
        return;
    for (int i = 0; i < ht->len; i++) {
        write(1, "[", 1);
        print_nbr(i);
        write(1, "]:\n", 3);
        disp_arg(ht->tables[i]);
    }
}
