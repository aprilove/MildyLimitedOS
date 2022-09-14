#include "../include/utils.h"

#define RAND_MAX 0x7fffffff

// Use a linear congrutenial generator 
uint32_t rseed = 0;

void seed(uint32_t s)
{
    rseed = s;
}

uint32_t rand(void) 
{
    return rseed = (rseed * 1103515245 + 12345) & RAND_MAX;
}

