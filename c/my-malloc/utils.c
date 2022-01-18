/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-maxime.dodin
** File description:
** utils
*/

#include "malloc.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int n)
{
    if (n < 0)
    {
        my_putchar('-');
        n = -n;
    }
    if (n >= 10)
    {
        my_put_nbr(n / 10);
        my_putchar(n % 10 + '0');
    }
    if (n < 10)
    {
        my_putchar(n % 10 + '0');
    }
    return (n);
}

void *singleton_malloc(struct_t *new_ptr)
{
    static void *old_ptr = NULL;
    if (new_ptr != NULL)
    {
        old_ptr = new_ptr;
    }
    return old_ptr;
}

int power_of_two(size_t size)
{
    int power = 2;

    if (size == 0)
        return 2;

    while (power < (int)size)
        power *= 2;
    return power;
}

struct_t *best_fit(struct_t *heap, size_t s)
{
    struct_t *best_feat = NULL;
    int value = -1;

    while (heap != NULL)
    {
        if (heap->free == true && heap->size >= (s + (sizeof(*heap)))
            && (value == -1 || value > (int)heap->size))
        {
            value = heap->size;
            best_feat = heap;
        }
        heap = heap->next;
    }
    if (value == -1)
        return NULL;
    return (best_feat);
}