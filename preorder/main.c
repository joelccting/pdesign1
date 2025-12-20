#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SZ (1010)

void preorder(int a[], const int n, const int i)
{
    printf("%d ", a[i]);
    if ((2 * i + 1) < n) preorder(a, n, 2 * i + 1);
    if ((2 * i + 2) < n) preorder(a, n, 2 * i + 2);
}

int main()
{
    int n, a[SZ];

    memset(a, -1, SZ * sizeof(int));
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
    }

    preorder(a, n, 0);

    return 0;
}

