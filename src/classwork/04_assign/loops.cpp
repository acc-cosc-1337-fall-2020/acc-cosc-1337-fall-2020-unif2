//cpp
#include "loops.h"

int factorial(int num)
{
    int prod = 1;

    for(int cnt = 1; cnt <= num; cnt++)
    {
        prod = prod * cnt;
    }

    return prod;
}