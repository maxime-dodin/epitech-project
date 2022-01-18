/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-maxime.dodin
** File description:
** malloc
*/

#include "malloc.h"

struct_t *split_block(struct_t *old_heap, size_t s)
{
    struct_t *new_heap = NULL;

    new_heap = (void *)old_heap + sizeof(*old_heap) + s;
    new_heap->size = old_heap->size - sizeof(*old_heap) - s;
    new_heap->next = NULL;
    new_heap->prev = old_heap;
    new_heap->free = true;

    if (old_heap && old_heap->next)
    {
        new_heap->next = old_heap->next;
    }
    old_heap->size = s;
    old_heap->next = new_heap;
    old_heap->free = false;
    return old_heap;
}

struct_t *create_heap(struct_t *_heap)
{
    _heap = sbrk(0);
    if (sbrk(PAGE_SIZE) == (void *)-1)
        return (NULL);
    _heap->size = (PAGE_SIZE - (sizeof(*_heap)));
    _heap->next = NULL;
    _heap->prev = NULL;
    _heap->free = true;
    return _heap;
}

struct_t *extend_heap(struct_t *_heap, size_t size)
{
    if (_heap == NULL)
    {
        if ((_heap = create_heap(_heap)) == NULL)
            return NULL;
        singleton_malloc(_heap);
    }
    else
    {
        if (sbrk(PAGE_SIZE) == (void *)-1)
            return (NULL);
        _heap->size += PAGE_SIZE;
    }
    if (size >= (size_t)PAGE_SIZE)
        _heap = extend_heap(_heap, ((size)-PAGE_SIZE));
    return (_heap);
}

void *malloc_block(struct_t *temp, size_t size)
{
    if ((temp = best_fit(temp, size)) != NULL)
    {
        if (temp->size >= (size + sizeof(*temp)))
            temp = split_block(temp, size);
    }
    else
    {
        temp = singleton_malloc(NULL);
        for (; temp->next != NULL; temp = temp->next);
        temp = extend_heap(temp, size);
        temp = split_block(temp, size);
    }
    return temp;
}

void *malloc(size_t size)
{
    struct_t *ptr, *temp;

    size = power_of_two(size);
    if (singleton_malloc(NULL))
    {
        temp = singleton_malloc(NULL);
        temp = malloc_block(temp, size);
    }
    else
    {
        if ((ptr = extend_heap(NULL, size)) == NULL)
            return NULL;
        temp = split_block(ptr, size);
    }
    return (temp + 1);
}