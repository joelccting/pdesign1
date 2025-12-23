#include <stdio.h>
#include <stdlib.h>

typedef long long LL;

int main()
{
    int n;
    LL a, b;
    LL m[] = {2, 3, 5};
    int cards = 0;

    scanf("%d", &n);
    while (n--)
    {
        scanf("%lld %lld", &a, &b);
        cards = 0;
        if (a == b)
        {
            printf("0\n");
            continue;
        }

        if ((a == 0) || (b == 0) || ((b % a) != 0))
        {
            printf("-1\n");
            continue;
        }

        LL r = b / a;

        for (int j = 0; j < 3; ++j)
        {
            while ((r % m[j]) == 0)
            {
                r /= m[j];
                cards++;
            }
        }

        if (r != 1) printf("-1\n");
        else printf("%d\n", cards);
    }
    return 0;
}
