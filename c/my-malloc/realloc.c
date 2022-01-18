/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-maxime.dodin
** File description:
** realloc
*/

#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
    struct_t *tmp = singleton_malloc(NULL);

    size = power_of_two(size);
    if (!ptr)
        return malloc(size);
    for (; tmp && tmp->next != NULL; tmp = tmp->next)
    {
        if (ptr == (tmp + 1))
        {
            if (tmp->size >= size)
                return (tmp + 1);
            else
            {
                tmp->free = true;
                ptr = memcpy(malloc(size), ptr, strlen(ptr) + 1);
            }
        }
    }
    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
    struct_t *ptr = malloc(size * nmemb);

    if (ptr)
        ptr = memset(ptr, 0, power_of_two(size * nmemb));
    return ptr;
}