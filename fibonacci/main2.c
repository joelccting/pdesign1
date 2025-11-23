#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;
const ULL m = (1e+9 + 7);

#define DBG (0)

/**
                                         2k
    |F(2k+1)|   | 1 1 | |F(2k)  |   | 1 1 |     |F(1)|   |F(k+1)  F(k)  | . |F(k+1)  F(k)  | |1|
    |F(2k)  | = | 1 0 | |F(2k-1)| = | 1 0 |     |F(0)| = |F(k)    F(k-1)|   |F(k)    F(k-1)| |0|

    F(2k+1) = F(k+1)*F(k+1)+F(k)*F(k)
    F(2k) = [F(k+1)+F(k-1))]*F(k) = [2*F(k+1)-F(k))]*F(k)

 */

void fastDoubling(ULL *fk1, ULL *fk)
{
    ULL tmp0 = *fk % m,
        tmp1 = *fk1 % m;
    ULL tmp;

//    tmp = tmp0;
//    tmp *= tmp;
//    tmp %= m;
//    *fk_1 = tmp;
//    tmp = tmp1;
//    tmp *= tmp1;
//    tmp %= m;
//    *fk_1 += tmp;
//    *fk_1 %= m;
    *fk1 = (tmp0 * tmp0 % m + tmp1 * tmp1 % m) % m;

    if (tmp1 >= tmp0) tmp = tmp1 - tmp0;
    else tmp = m + tmp1 - tmp0;

    tmp += tmp1;
    tmp %= m;
    tmp *= tmp0;
    *fk = tmp % m;
 //   *fk = ((2 * tmp1 - tmp0) * tmp0) % m;
}

void getFib(ULL k, ULL *fk1, ULL *fk0)
{
    if (k == 0)
    {
        *fk1 = 1;
        *fk0 = 0;
        return;
    }

    getFib(k >> 1, fk1, fk0);
#if DBG
    printf("k=%llu [%llu,%llu]\n", k >> 1, *fk1, *fk0);
#endif // DBG
    fastDoubling(fk1, fk0);

    if (k & 1) // odd
    {
        ULL fk2 = *fk0;
        *fk0 = *fk1;
        *fk1 = (fk2 + *fk0);
    }

}

ULL fib(ULL k)
{
    if (k == 0) return 0;
    if (k == 1) return 1;
    return fib(k - 1) + fib(k - 2);
}

ULL fastFib(ULL k)
{
    ULL fk0, fk1;
    getFib(k, &fk1, &fk0);

//    if (k & 1) return fk1;

    return fk0;
}

int main()
{
    ULL n;
    scanf("%llu", &n);

#if DBG
    for (int i = 0; i <= n; ++i)
        printf("[%d] %llu\n", i, fib(i));
#endif // DBG

    if (n == 0) printf("0");
    else printf("%llu", fastFib(n));

    return 0;
}
