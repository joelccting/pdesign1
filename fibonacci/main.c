#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;
const ULL m = 1000000007;

void print(ULL *a)
{
    printf("| %llu, %llu |\n", a[1] + a[0], a[1]);
    printf("| %llu, %llu |\n", a[1], a[0]);
}

/** F(2k) = F(k)* (2*F(k-1)+F(k))
 */
void compute(ULL *u)
{
    ULL tmp[2];

//    tmp[1] = (u[1] * u[1] + u[0] * u[0]) % m;
    tmp[1] = u[1] * u[1];
    tmp[1] += u[0] * u[0];
    tmp[1] %= m;
//    tmp[0] = u[0] * (2 * u[1] - u[0]) % m;
    tmp[0] = u[0] * (2 * u[1] - u[0]);
    tmp[0] %= m;

    u[1] = tmp[1];
    u[0] = tmp[0];
}

void fib2(ULL *u, ULL k)
{
    ULL tmp;

    if (k == 0)
    {
        u[0] = 0;
        u[1] = 1;
        return;
    }

    fib2(u, k / 2);
    compute(u);

    if (k % 2) //odd
    {
        tmp = u[0];
        u[0] = u[1];
        u[1] = tmp + u[1];
    }
}

#if 1
void fib_fast_doubling(ULL k, ULL *f_n, ULL *f_n1)
{
    if (k == 0)
    {
        *f_n = 0;
        *f_n1 = 1;
        return;
    }

    ULL a, b;
    fib_fast_doubling(k >> 1, &a, &b);

    ULL c = a * (2 * b - a); c %= m;
    ULL d = a * a + b * b; d %= m;

    if (k & 1)
    {
        *f_n = d;
        *f_n1 = c + d;
    }
    else
    {
        *f_n = c;
        *f_n1 = d;
    }
}

ULL fib(ULL k)
{
    //ULL fn, fn1;
    //fib_fast_doubling(k, &fn, &fn1);

    ULL a[2];
    fib_fast_doubling(k, &(a[0]), &(a[1]));
    //print(a);
    return a[0];
}
#endif

int main()
{
    ULL n;
    scanf("%llu", &n);
#if 0
    ULL a[2];

    for (int i = 1; i < 25; ++i) {
        printf("---%d---\n", i);
        n = i;
        fib2(a, n);
        //printf("%llu", a[0]);
        print(a);
    }
#endif
    printf("%llu", fib(n));

    return 0;
}
