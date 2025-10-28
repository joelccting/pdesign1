#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;

void init(ULL *anum, int n, const int m)
{
    for (int i = 3; i <= n; ++i)
    {
        anum[i] = 0;

        for (int j = i - 2; j > 0; --j )
        {
            anum[i] += (anum[j] % m);
            anum[i] %= m;
        }

    }
}

int main()
{
    ULL anum[1001]; //additional number each year
    int n;
    const int m = 1000000007;

    anum[1] = anum[2] = 2;
    init(anum, 1000, m);

    while(scanf("%d", &n) != EOF)
    {
        ULL sum = 0;

//        for (int i = 3; i <= n; ++i)
//        {
//            anum[i] = 0;
//
//            for (int j = i - 2; j > 0; --j )
//            {
//                anum[i] += (anum[j] % m);
//                anum[i] %= m;
//            }
//
//        }

        for (int i = 1; i <= n; ++i)
        {
            sum += anum[i];
            sum %= m;
        }

        printf("%llu\n", sum);
    }

    return 0;
}
