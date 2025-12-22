#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DBG (1)

#if DBG
#define dbg(s, b...) printf(s, ##b);
#else
#define dbg(s, b...)
#endif // DBG

typedef unsigned long long ULL;

ULL getDigits(ULL n)
{
    char str[21] = {0};
    snprintf(str, 20, "%lld", n);
    //printf("str=%s\n", str);
    return strlen(str);
}

ULL getUpperBound(ULL n)
{
    ULL ret = 9;
    for (ULL i = 1; i < n; ++i)
    {
        ret *= 10;
        ret += 9;
    }
    return ret;
}

int main()
{
    int n;
    ULL a, b;

    scanf("%d", &n);

    while (n > 0)
    {
        scanf("%llu %llu", &a, &b);
        ULL d = getDigits(b);
        if (b == getUpperBound(d)) printf("%llu\n", a * d);
        else printf("%llu\n", a * (d - 1));
        --n;
    }

    return 0;
}


