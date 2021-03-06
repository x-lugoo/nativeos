/*
 * This file is part of NativeOS
 * Copyright (C) 2015-2018 The NativeOS contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>

/**
 * @file libc/src/string.c
 * @brief implementation of functions defined in string.h
 */

char* strcpy(char* dst, const char* src)
{
    /* The moving pointer that we'll use to change dst. */
    char* ptr = dst;

    /* Start copying characters. */
    while (*src) {
        *ptr++ = *src++;
    }

    /* Return pointer to the original string. */
    return dst;
}

char* strncpy(char *dst, const char *src, size_t len)
{
    /* The moving pointer that we'll use to not change dst. */
    char* ptr = dst;

    /* Copy characters. */
    while (len--) {
        /* Stop copying if we have reached the end of the string. */
        if (!(*ptr++ = *src++)) {
            break;
        }
    }

    /* Read the docs -- the remaining of the string is filled with \0. */
    while (len--) {
        *ptr++ = 0;
    }

    /* Return a pointer to the original string to copy. */
    return dst;
}

size_t strlen(const char* s)
{
    const char* ptr;
    for (ptr = s; *ptr; ptr++);
    return (ptr - s);
}

int strcmp(const char *s1, const char *s2)
{
    unsigned char *cmp1 = (unsigned char *) s1;
    unsigned char *cmp2 = (unsigned char *) s2;

    while (*cmp1 && *cmp2) {
        if (*cmp1 != *cmp2) {
            /* Characters on this position do not match. Break. */
            return (*cmp1 - *cmp2);
        }
        cmp1++;
        cmp2++;
    }

    /* They didn't say which positive or negative number had to be returned. */
    return (*cmp1 - *cmp2) > 0 ? 1 : -1;
}

int strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char *cmp1 = (unsigned char *) s1;
    unsigned char *cmp2 = (unsigned char *) s2;

    if (n == 0) {
        /* Early bail out. */
        return 0;
    }

    /* *cmp1 && *cmp2 will bail out once NUL is reached for any string. */
    while (*cmp1 && *cmp2 && n--) {
        if (*cmp1 != *cmp2) {
            /* Characters on this position do not match. Break. */
            return (*cmp1 - *cmp2);
        }
        cmp1++;
        cmp2++;
    }

    /* They didn't say which positive or negative number had to be returned. */
    return (*cmp1 - *cmp2) > 0 ? 1 : -1;
}
