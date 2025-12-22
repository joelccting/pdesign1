#include <stdio.h>
#include <stdlib.h>

#define DBG (0)

#if DBG
#define dbg(s, b...) printf(s, ##b);
#else
#define dbg(s, b...)
#endif // DBG

typedef unsigned long long ULL;

int getLen(const ULL a)
{
    ULL t = a;
    int d = 0;

    while (t)
    {
        t /= 10;
        d++;
    }

    dbg("d=%d\n", d);
    return d;
}

int main()
{
    int n;
    ULL a, b, calc, comb, cnt = 0;

    scanf("%d", &n);

    while (n > 0)
    {
        scanf("%llu %llu", &a, &b);



        for (int i = 1; i <= a; ++i)
        {
            for (int j = 1; j <= b; ++j)
            {
                calc = i + j + i * j;
                comb = i;
                for (int k = 0; k < getLen(j); ++k) comb *= 10;
                comb += j; dbg("calc=%llu, comb=%llu\n", calc, comb);
                if (calc == comb)
                {
                    ++cnt;
                }

            }
        }

        dbg("cnt=");
        printf("%llu\n", cnt);

        --n;
    }

    return 0;
}
