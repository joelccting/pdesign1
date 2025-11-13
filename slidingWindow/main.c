#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int slidingWindow(int *a, const int size, const int target)
{
    int start = 0, end = 0, sum = 0, minLen = 100000;

    for (end = 0; end < size; ++end)
    {
        sum += a[end];
#if DBG
        printf("+");
        for (int i = start; i < end + 1; ++i) printf("%d,", a[i]); printf("\n");
#endif // DBG
        while (sum >= target)
        {
            if (minLen > (end - start + 1))
            {
                minLen = (end - start + 1);
            }

            sum -= a[start];
            ++start;
        }
#if DBG
        printf("-");
        for (int i = start; i < end + 1; ++i) printf("%d,", a[i]); printf("\n");
#endif // DBG
    }

    return minLen;
}

int main()
{
    int n, t, sum = 0;

    scanf("%d %d", &n, &t);

    int *a = (int *) malloc(sizeof(int) * n);
    memset(a, 0, sizeof(int) * n);

    for (int i = 0; i < n; ++i)
    {
        scanf(" %d", &(a[i]));
        sum += a[i];
    }

    if (sum < t) printf("-1");
    else printf("%d", slidingWindow(a, n, t));

    free(a);
    return 0;
}
