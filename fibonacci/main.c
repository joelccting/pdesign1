#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;
const ULL m = 1000000007;

void mod(ULL *u)
{
    u[0] %= m;
    u[1] %= m;
    u[2] %= m;
}

void mul2(ULL *u, ULL *v)
{
    ULL tmp[3];

    mod(u);
    mod(v);
    tmp[2] = u[2] * v[2] % m + u[1] * v[1] % m;
    tmp[1] = u[1] * v[2] % m + u[0] * v[1] % m;
    tmp[0] = u[1] * v[1] % m + u[0] * v[0] % m;
    mod(tmp);
    u[2] = tmp[2];
    u[1] = tmp[1];
    u[0] = tmp[0];
}

void print(ULL *a)
{
    printf("+ %llu, %llu\n", a[2], a[1]);
    printf("- %llu, %llu\n", a[1], a[0]);
}

void mul(ULL *u, ULL k)
{
    ULL tmp1[3];

    if (k == 1)
    {
         u[0] = 0;
         u[1] = 1;
         u[2] = 1;
         return;
    }

    if (k == 2)
    {
         u[0] = 1;
         u[1] = 1;
         u[2] = 2;
         return;
    }

    mul(u, k / 2);
    mul(tmp1, k - k / 2);
    mul2(u, tmp1);
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
        mul(a, n);
        //print(a);
        printf("%llu", a[1]);
    }

    return 0;
}
