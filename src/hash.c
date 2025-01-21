/*
** EPITECH PROJECT, 2025
** B-CPE-110-NAN-1-1-secured-alexis.clemot
** File description:
** hash
*/

#include "hashtable.h"
#include <stdint.h>

uint32_t rotate_left(uint32_t value, int shift)
{
    return (value << shift) | (value >> (32 - shift));
}

uint32_t rotate_right(uint32_t value, int shift)
{
    return (value >> shift) | (value << (32 - shift));
}

uint32_t mix_bits(uint32_t a, uint32_t b)
{
    a ^= b;
    a = rotate_left(a, 13);
    a += b;
    a ^= rotate_right(b, 11);
    a ^= (a << 7) | (a >> 25);
    a ^= (b >> 3) | (b << 29);
    return a;
}

uint32_t verif_hash_size(uint32_t hash)
{
    for (int i = 0; hash >= 2147483648; i++) {
        hash -= 2147483647;
    }
    return hash;
}

int hash(char *key, int len)
{
    uint32_t hash = 0xDEADBEEF;
    uint8_t byte;

    if (!key || len < 1)
        return 84;
    for (int i = 0; key[i] != '\0'; i++) {
        byte = (uint8_t)key[i];
        hash = mix_bits(hash, byte + i * 31);
    }
    hash ^= rotate_left(hash, 16);
    hash ^= rotate_right(hash, 11);
    hash ^= (hash << 5);
    hash = verif_hash_size(hash);
    return (int)(hash & 0xFFFFFFFF);
}
