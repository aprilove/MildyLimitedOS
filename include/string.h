#ifndef STRING_H
#define STRING_H

#include "../include/utils.h"

#define swap(a, b) (a ^= b ^= a ^= b)

int32_t memcmp(const void *aptr, const void *bptr, size_t n);

void memset(void *bufptr, uint8_t value, size_t n);

size_t strlen(const char *str);

char *strcpy(char *dest, const char *src);

int32_t strcmp(const char *s1, const char *s2);

void itoa(char *s, int32_t num, int32_t base);

char *ctos(char s[2], const char c);

#endif
