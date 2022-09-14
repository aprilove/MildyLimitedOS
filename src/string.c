#include "../include/string.h"
#include "../include/utils.h"

void reverse(char inStr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        swap(*(inStr + start), *(inStr + end));
        start++;
        end--;
    }
}

int32_t memcmp(const void *aptr, const void *bptr, size_t n)
{
    const unsigned char *a = (const unsigned char *)aptr;
    const unsigned char *b = (const unsigned char *)bptr;
    size_t i;
    for (i = 0; i < n; i++)
        if (a[i] < b[i])
            return -1;
        else if (b[i] < a[i])
            return 1;
    return 0;
}

void memset(void *inBufptr, uint8_t value, size_t n)
{
    uint8_t *w = inBufptr;
    while (--n > 0)
    {
        *(++w) = value;
    }
}

size_t strlen(const char *inStr)
{
    size_t ret = 0;
    while (inStr[ret] != 0)
        ret++;
    return ret;
}

char *strcpy(char *dest, const char *src)
{
    char *tmp = dest;
    while ((*dest++ = *src++) != 0)
    {
    }
    return tmp;
}

int32_t strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
        s1++, s2++;
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

void itoa(char *inStr, int32_t inNum, int32_t inBase)
{
    int32_t i = 0;
    bool_t neg = false;

    if (inNum == 0)
    {
        inStr[i++] = '0';
        inStr[i] = '\0';
    }

    if (inNum < 0 && inBase == 10)
    {
        neg = true;
        inNum = -inNum;
    }

    while (inNum != 0)
    {
        int32_t rem = inNum % inBase;
        inStr[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        inNum = inNum / inBase;
    }

    if (neg)
    {
        inStr[i++] = '-';
    }

    inStr[i] = '\0';
    reverse(inStr, i);
}

char *ctos(char s[2], const char c)
{
    s[0] = c;
    s[1] = '\0';
    return s;
}
