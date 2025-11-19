#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;
const ULL m = 1000000007;

void print(ULL *a)
{
    printf("+ %llu, %llu\n", a[2], a[1]);
    printf("- %llu, %llu\n", a[1], a[0]);
}

void fib(ULL *u, ULL k)
{
    if (k == 0)
    {
        return;
    }

    if (k == 1)
    {
         u[0] = u[1] % m;
         u[1] = u[2] % m;
         u[2] = (u[1] % m + u[0] % m) % m;
         return;
    }

    if (k % 2 == 0)
    {
        fib(u, k / 2);
        fib(u, k / 2);
    }
    else //odd
    {
        fib(u, (k - 1) / 2);
        fib(u, (k - 1) / 2);
        fib(u, 1);
    }
}

int main()
{
    ULL n;
    scanf("%llu", &n);
    ULL a[3] = {0, 1, 1};

    if (n == 0)
    {
        printf("0");
    }
    else
    {
        fib(a, n);
        //print(a);
        printf("%llu", a[0]);
    }

    return 0;
}
