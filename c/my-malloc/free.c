/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-maxime.dodin
** File description:
** free
*/

#include "malloc.h"

struct_t *merge_block(struct_t *b)
{
    b->size += sizeof(*b) + b->next->size;
    b->next = b->next->next;
    if (b->next)
        b->next->prev = b;
    return (b);
}

void free(void *p)
{
    struct_t *tmp = singleton_malloc(NULL);
    while (tmp && tmp->next != NULL)
    {
        if (p == (tmp + 1))
        {
            tmp->free = true;
            // if (tmp->prev && tmp->prev->free)
            //     tmp = merge_block(tmp->prev);
            // if (tmp->next && tmp->next->free)
            //     merge_block(tmp);
            return;
        }
        tmp = tmp->next;
    }
}