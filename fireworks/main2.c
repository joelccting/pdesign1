// midterm
// 1215

#include <stdio.h>
#include <stdlib.h>

#define DBG (0)

int a[10];
int copy[10];
int check[10];
long long ans;

void mark(int sz, int k)
{
    int cnt = 0;
    for (int i = 0; i < sz - 2; ++i)
    {
        if ((copy[i + 1] > copy[i]) && (copy[i + 2] < copy[i + 1]))
        {
            cnt++;
        }
    }

    ans += (cnt >= k);
#if DBG
    printf("cnt/ans: %d/%d\n", cnt, ans);
#endif
}

void permute(int level, int n, int k)
{
    if (level == n)
    {
#if DBG
        for (int j = 0; j < n; ++j) printf("%d ", copy[j]);
        printf("\n");
#endif
        mark(n, k);
    }

    for (int i = 0; i < n; ++i)
    {
        if (check[i] == 0)
        {
            check[i] = 1;
            copy[level] = a[i];
            permute(level + 1, n, k);
            check[i] = 0;
        }
    }
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i)
    {
        scanf(" %d", a + i);
        check[i] = 0;
    }

    permute(0, n, k);

    printf("%lld", ans);

    return 0;
}
