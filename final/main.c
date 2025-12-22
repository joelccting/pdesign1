#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;

ULL sigma(ULL n)
{
    ULL ret = 0;
    ULL MOD = 1000000007ULL;

    for (ULL i = 1; i * i <= n; ++i)
    {
        if ((n % i) != 0)
        {
            continue;
        }

//        if ((n % i) == 0)
//        {
            ret += (i % MOD);
            ret += (n / i) % MOD;
//        }

        if (i * i == n)
        {
            ret -= (n / i) % MOD;
        }
    }

    //printf("%llu\n", ret);

    return ret % MOD;
}

ULL sigma2(ULL n)
{
    ULL factor = 2, sum, term, ret = 1;

    while (factor * factor <= n)
    {
        if (n % factor == 0)
        {
            sum = 1;
            term = 1;
            while (n % factor == 0)
            {
                n /= factor;
                term *= factor;
                sum += term;
            }

            ret *= sum;
        }

        factor++;
    }

    if (n > 1)
    {
        ret *= (1 + n);
    }

    return ret;
}

int main()
{
    ULL n, MOD = 1000000007ULL, sum = 0;
    scanf("%llu", &n);

#if 0 /* TIMEOUT */
    for (ULL i = 1; i <= n; ++i)
    {
        sum += sigma(i);
        sum %= MOD;
    }
#endif

#if 0 /* TIMEOUT */
    for (ULL i = 1; i <= n; ++i)
    {
        sum += (n / i) * i;
        sum %= MOD;
    }
#endif // 0
    for (ULL i = 1; i <= n; ++i)
    {
        sum += sigma2(i);
        sum %= MOD;
    }

    printf("%llu", sum);

    return 0;
}
