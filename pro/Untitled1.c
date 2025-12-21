#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DBG (0)

typedef unsigned long long ULL;
typedef long long LL;

bool isPrime(int x)
{
    bool ret = true;

    if (x == 2) return true;

    for (int i = 2; i * i <= x; ++i)
    {
        if ( x % i == 0)
        {
            ret = false;
            break;
        }
    }

    return ret;
}

/* prime multiplication
 */
LL getPrimMul(int p[], int psz, int mask)
{
    ULL cnt = 0;
    LL ans = 1;

    for (ULL i = 0; i < psz; i++)
    {
        if (mask & (1 << i))
        {
            ans *= p[i];
            cnt++;
        }
    }

    if (cnt % 2 == 0) ans *= -1;
#if DBG
    printf("mask=%x, ans=%lld\n", mask, ans);
#endif
    return ans;
}

int main()
{
    LL x;
    unsigned y;
    int pnum[50] = {0}, pidx = 0;

    scanf("%llu %u", &x, &y);

    for (int i = 2; i <= y; ++i)
    {
        if (isPrime(i)) pnum[pidx++] = i;
    }

#if 0
    for (int i = 0; i < pidx; ++i)
    {
        printf("%d ", pnum[i]);
    }
    printf("\n");
#endif

    LL total = x;
    for (ULL i = 1; i < (1 << pidx); ++i)
    {
        LL tmp = getPrimMul(pnum, pidx, i);
        total -= x / tmp;
#if DBG
        printf("total=%lld\n", total);
#endif
    }

    printf("%lld\n", total);

    return 0;
}
