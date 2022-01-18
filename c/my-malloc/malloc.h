/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-maxime.dodin
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include <dlfcn.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>


#include <sys/syscall.h>

#define PAGE_SIZE (12 * sysconf(_SC_PAGESIZE))

typedef struct struct_s
{
    size_t size;
    struct struct_s *next;
    struct struct_s *prev;
    int free;
} struct_t;

int power_of_two(size_t size);
void *singleton_malloc(struct_t *new_ptr);
int my_put_nbr(int n);
struct_t *best_fit(struct_t *heap, size_t s);

struct_t *merge_block(struct_t *b);
void free(void *p);

void *realloc(void *ptr, size_t size);
void *calloc(size_t nmemb, size_t size);

struct_t *split_block(struct_t *old_heap, size_t s);
struct_t *extend_heap(struct_t *_heap, size_t size);
void *malloc(size_t size);


#endif /* !MALLOC_H_ */
