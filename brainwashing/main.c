#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;

void setMonInc(ULL *a, int days)
{
    int from;

    a[0] = 2; // original two
    a[1] = 0;

    for (int i = 2; i <= days; ++i)
    {
        a[i] = 0;
        from = 0;

        if (i > 11) from = i - 11;

        for (int j = i - 2; j >= from; --j)
        {
            a[i] += a[j];
        }
    }

}

int main()
{
    ULL inc[101];
    int n;
    scanf("%d", &n);

    setMonInc(inc, 50);
//    for (int i =0; i <= 30; ++i)
//    {
//        printf("%02d: %d\n", i, inc[i]);
//    }

    ULL sum = 0;
    for (int i = 0; i <= n; ++i)
    {
        sum += inc[i];
//        printf("%02d: %llu\n", i, sum);
    }

//    printf("%d", inc[n]);
    printf("%llu", sum);
    return 0;
}
