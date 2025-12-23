#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;
const ULL MOD = 1000000007ULL;

int main()
{
    ULL n, sum = 0;
    scanf("%llu", &n);
    //printf("sizeof(ULL)=%d\n", sizeof(ULL));

    for (ULL i = 1; i <= n; ++i)
    {
        ULL t = i * (n / i);
        t %= MOD;
        sum += t;
        sum %= MOD;
    }

    printf("%llu", sum);

    return 0;
}
