#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <criterion/criterion.h>

size_t my_strlen(char *);
char *my_strchr(const char *s, int c);
void *my_memset(void *s, int c, size_t n);
void *my_memcpy(void *dest, const void *src, size_t n);
char *my_strcpy(char *dest, const char *src);
int my_strcmp(const char *s1, const char *s2);
void *my_memmove(void *dest, const void *src, size_t n);
int my_strncmp(const char *s1, const char *s2, size_t n);
int my_strcasecmp(const char *s1, const char *s2);
char *my_rindex(const char *s, int c);
//char *(const char *haystack, const char *needle);
char *my_strpbrk(const char *s, const char *accept);
size_t my_strcspn(const char *s, const char *reject);

// Test(strlen, small)
// {
//     char *str = "PLOUF";
//     size_t got = my_strlen(str);
//     size_t expected = strlen(str);

//     cr_expect_eq(expected, got, "Got: %zu | Expected: %zu\n", got, expected);
// }

// Test(strlen, medium)
// {
//     char *str = "PLOUFkjdzhfdadlhddjfd";
//     size_t got = my_strlen(str);
//     size_t expected = strlen(str);

//     cr_expect_eq(expected, got, "Got: %zu | Expected: %zu\n", got, expected);
// }

// Test(strlen, big)
// {
//     char *str = "PLOUFkjdzhfdadlhddjfdlkadadsjkadlkjada" \
//     "akjsafahfashfasjfhafsmhamfshamsfjah";
//     size_t got = my_strlen(str);
//     size_t expected = strlen(str);

//     cr_expect_eq(expected, got, "Got: %zu | Expected: %zu\n", got, expected);
// }

// Test(strcmp, ok)
// {
//     const char *str1 = "PLOUF";
//     const char *str2 = "PLOUF";
//     int got = my_strcmp(str1, str2);
//     int expected = strcmp(str1, str2);

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }


// Test(strcmp, KO_1)
// {
//     const char *str1 = "adasadsads";
//     const char *str2 = "PLOUF";
//     int got = my_strcmp(str1, str2);
//     int expected = strcmp(str1, str2);

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }

// Test(strcmp, KO_2)
// {
//     const char *str1 = "PLOU";
//     const char *str2 = "PLOUF";
//     int got = my_strcmp(str1, str2);
//     int expected = strcmp(str1, str2);

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }


// Test(strcmp, KO_3)
// {
//     const char *str1 = "PLOUF1";
//     const char *str2 = "PLOUF";
//     int got = my_strcmp(str1, str2);
//     int expected = strcmp(str1, str2);

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }

// Test(strncmp, ok)
// {
//     const char *str1 = "PLOUF";
//     const char *str2 = "PLOUF";
//     size_t n = 3;
//     int got = my_strncmp(str1, str2, n);
//     int expected = strncmp(str1, str2, n);

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }

// Test(strncmp, n_equal_to_len)
// {
//     const char *str1 = "PLOUF";
//     const char *str2 = "PLOUF";
//     size_t n = strlen(str1);
//     int got = my_strncmp(str1, str2, n);
//     int expected = strncmp(str1, str2, n);

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }

// Test(strncmp, ko2)
// {
//     const char *str1 = "PLOUF";
//     const char *str2 = "PLOUFadadada";
//     size_t n = strlen(str1);
//     int got = my_strncmp(str1, str2, n);
//     int expected = strncmp(str1, str2, n);

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }

// Test(strncmp, ok_n_sup)
// {
//     const char *str1 = "PLOUF";
//     const char *str2 = "PLOUF";
//     size_t n = 200;
//     int got = my_strncmp(str1, str2, n);
//     int expected = strncmp(str1, str2, n);

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }


// Test(strncmp, ko)
// {
//     const char *str1 = "PLAF";
//     const char *str2 = "PLOUF";
//     size_t n = 3;
//     int got = my_strncmp(str1, str2, n);
//     int expected = strncmp(str1, str2, n);

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }


// Test(strncmp, ko_n_sup)
// {
//     const char *str1 = "PLAF";
//     const char *str2 = "PLOUF";
//     size_t n = 2000;
//     int got = my_strncmp(str1, str2, n);
//     int expected = strncmp(str1, str2, n);

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }

// Test(memcpy, test_tutorialspoint)
// {
//     const char src[50] = "http://www.tutorialspoint.com";
//     char got[50];
//     char expected[50];

//     my_memcpy(got, src, strlen(src) + 1);
//     memcpy(expected, src, strlen(src) + 1);

//     cr_expect_str_eq(expected, got, "Got: %s | Expected: %s\n", got, expected);
// }

// Test(memset, test_tutorialspoint)
// {
//     char expected[50];
//     char got[50];
//     strcpy(expected,"This is string.h library function");
//     strcpy(got,"This is string.h library function");


//     memset(expected,'$',7);
//     my_memset(got, '$', 7);
//     cr_expect_str_eq(expected, got, "Got: %s | Expected: %s\n", got, expected);
// }

// Test(memmove, test_tutorialspoint)
// {
//     char expected[] = "Firststring";
//     char got[] = "Firststring";
//     const char b[] = "Secondstring";

//     memmove(expected, b, 9);
//     my_memmove(got, b, 9);
//     cr_expect_str_eq(expected, got, "Got: %s | Expected: %s\n", got, expected);
// }

// Test(memmove, test_geeks_for_geeks)
// {
//     char str[100] = "Learningisfun";
//     char *first;
//     char *expected;
//     char *got;
    
//     first = str;
//     expected = str;
//     got = str;

//     memmove(expected + 8, first, 10);
//     my_memmove(got + 8, first, 10);
//     cr_expect_str_eq(expected, got, "Got: %s | Expected: %s\n", got, expected);
// }

// Test(strcasecmp, min)
// {
//     char str1[] = "plouf";
//     char str2[] = "plouf";
//     char got = my_strcasecmp(str1, str2);
//     char expected = strcasecmp(str1, str2);;

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }

// Test(strcasecmp, edouard)
// {
//     char str1[] = "\x81";
//     char str2[] = "a";
//     char got = my_strcasecmp(str1, str2);
//     char expected = strcasecmp(str1, str2);;

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }

// Test(strcasecmp, tqt1)
// {
//     char str1[] = "[\\]^_`!#&)()";
//     char str2[] = "[\\]^_`!#&)()";
//     char got = my_strcasecmp(str1, str2);
//     char expected = strcasecmp(str1, str2);;

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }

// Test(strcasecmp, tqt2)
// {
//     char str1[] = "[\\]^_`";
//     char str2[] = "[\\]^_`";
//     char got = my_strcasecmp(str1, str2);
//     char expected = strcasecmp(str1, str2);;

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }

// Test(strcasecmp, maj)
// {
//     char str1[] = "PLOUF";
//     char str2[] = "PLOUF";
//     char got = my_strcasecmp(str1, str2);
//     char expected = strcasecmp(str1, str2);;

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }

// Test(strcasecmp, mix)
// {
//     char str1[] = "PlOuF";
//     char str2[] = "PLOUF";
//     char got = my_strcasecmp(str1, str2);
//     char expected = strcasecmp(str1, str2);;

//     cr_expect_eq(expected, got, "Got: %d | Expected: %d\n", got, expected);
// }

// Test(strchr, start)
// {
//     char str1[] = "PlOuF";
//     char *got = my_strchr(str1, 'P');
//     char *expected = strchr(str1, 'P');

//     cr_expect_str_eq(expected, got, "Got: %s | Expected: %s\n", got, expected);
// }

// Test(strchr, mid)
// {
//     char str1[] = "PlOuF";
//     char *got = my_strchr(str1, 'O');
//     char *expected = strchr(str1, 'O');

//     cr_expect_str_eq(expected, got, "Got: %s | Expected: %s\n", got, expected);
// }

// Test(strchr, end)
// {
//     char str1[] = "PlOuF";
//     char *got = my_strchr(str1, '\0');
//     char *expected = strchr(str1, '\0');

//     cr_expect_str_eq(expected, got, "Got: %s | Expected: %s\n", got, expected);
// }

// Test(strchr, undefined)
// {
//     char str1[] = "PlOuF";
//     char *got = my_strchr(str1, 'z');

//     cr_expect_null(got);
// }

Test(rindex, ok)
{
    char str1[] = "PlOOOOOOuF";
    char *got = my_rindex(str1, 'O');
    char *expected = rindex(str1, 'O');
    cr_expect_str_eq(expected, got, "Got: %s | Expected: %s\n", got, expected);
}

Test(rindex, undefined)
{
    char str1[] = "PlOOOOOOuF";
    char *got = my_rindex(str1, 'z');
    char *expected = rindex(str1, 'z');
    cr_expect_null(got);
    cr_expect_null(expected);
}

// Test(strstr, ok)
// {
    // char str1[] = "plifplafplouf";
    // char *got = (str1, "plaf");
    // char *expected = strstr(str1, "plaf");

    // cr_expect_str_eq(expected, got, "Got: %s | Expected: %s\n", got, expected);
// }

// Test(strstr, empty_str_1)
// {
//     char str1[] = "plifplafplouf";
//     char *got = (str1, "");
//     char *expected = strstr(str1, "");

//     cr_expect_str_eq(expected, got, "Got: %s | Expected: %s\n", got, expected);
// }


// Test(strstr, empty_str2)
// {
//     char str1[] = "";
//     char *got = (str1, "plaf");
//     char *expected = strstr(str1, "plaf");

//     cr_expect_null(got);
//     cr_expect_null(expected);
// }


// Test(strstr, empty_all)
// {
//     char str1[] = "";
//     char *got = my_strstr(str1, "");
//     char *expected = strstr(str1, "");

//     cr_expect_str_eq(expected, got, "Got: %s | Expected: %s\n", got, expected);
// }

// Test(strstr, ko)
// {
//     char str1[] = "plifplafplouf";
//     char *got = my_strstr(str1, "fafafafafaf");
//     char *expected = strstr(str1, "fafafafafaf");

//     cr_expect_null(expected);
//     cr_expect_null(got);
// }

Test(strpbrk, ok)
{
    char str1[] = "plifplafplafplouf";
    char *got = my_strpbrk(str1, "plaf");
    char *expected = strpbrk(str1, "plaf");

    cr_expect_str_eq(expected, got, "Got: %s | Expected: %s\n", got, expected);
}

Test(strpbrk, empty_first)
{
    char str1[] = "";
    char *got = my_strpbrk(str1, "plaf");
    char *expected = strpbrk(str1, "plaf");

    cr_expect_null(got);
    cr_expect_null(expected);
}

Test(strpbrk, empty_second)
{
    char str1[] = "plifplafplafplouf";
    char *got = my_strpbrk(str1, "");
    char *expected = strpbrk(str1, "");

    cr_expect_null(got);
    cr_expect_null(expected);
}

Test(strpbrk, empty_all)
{
    char str1[] = "";
    char *got = my_strpbrk(str1, "");
    char *expected = strpbrk(str1, "");

    cr_expect_null(got);
    cr_expect_null(expected);
}

Test(strpbrk, ko)
{
    char str1[] = "plifplafplafplouf";
    char *got = my_strpbrk(str1, "zvzvzvz");
    char *expected = strpbrk(str1, "zvzvzzv");

    cr_expect_null(expected);
    cr_expect_null(got);
}

Test(strpbrk, ko2)
{
    char str1[] = "plifplafplafplouf";
    char *got = my_strpbrk(str1, "fafafafafaf");
    char *expected = strpbrk(str1, "fafafafafaf");

    cr_expect_str_eq(expected, got, "Got: %s | Expected: %s\n", got, expected);
}

Test(strpbrk, empty)
{
    char str1[] = "plifplafplafplouf";
    char *got = my_strpbrk(str1, "");
    char *expected = strpbrk(str1, "");

    cr_expect_null(expected);
    cr_expect_null(got);
}

// Test(strcspn, no_occurence)
// {
//     char str1[] = "plifplafplafplouf";
//     size_t got = my_strcspn(str1, "plaf");
//     size_t expected = strcspn(str1, "plaf");

//     cr_expect_eq(expected, got, "Got: %zu | Expected: %zu\n", got, expected);
// }

// Test(strcspn, empty)
// {
//     char str1[] = "plifplafplafplouf";
//     size_t got = my_strcspn(str1, "");
//     size_t expected = strcspn(str1, "");

//     cr_expect_eq(expected, got, "Got: %zu | Expected: %zu\n", got, expected);
// }

// Test(strcspn, simple)
// {
//     char str1[] = "plifplafplafplouf";
//     size_t got = my_strcspn(str1, "oa");
//     size_t expected = strcspn(str1, "oa");

//     cr_expect_eq(expected, got, "Got: %zu | Expected: %zu\n", got, expected);
// }