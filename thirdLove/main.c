#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned long long ULL;

int main()
{
    ULL x, y;
    scanf("%llu %llu", &x, &y);

    if (y >= (ULLONG_MAX - x)) printf("No");
    else printf("Yes");


    return 0;
}
