#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;

int main()
{
    ULL x, y, cnt = 0;

    scanf("%llu %llu", &x, &y);

    if (x <= y) printf("%llu", x);
    else // x>y
        printf("%llu", x);


    return 0;
}
