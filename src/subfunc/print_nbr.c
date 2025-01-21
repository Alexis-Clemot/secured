/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/

#include <unistd.h>

static void display(char c)
{
    write(1, &c, 1);
}

static void display_nbr(unsigned long long nb)
{
    int disgit;

    if (nb > 0) {
        disgit = nb % 10;
        if ((nb - disgit) != 0) {
            display_nbr((nb - (nb % 10)) / 10);
        }
    }
    display(disgit + 48);
}

void print_nbr(unsigned long long nb)
{
    if (nb == 0)
        write(1, "0", 1);
    else
        display_nbr(nb);
}
