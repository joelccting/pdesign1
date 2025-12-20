#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SZ (1010)

void postorder(int a[], const int n, const int i)
{
    if ((2 * i + 1) < n) postorder(a, n, 2 * i + 1);
    if ((2 * i + 2) < n) postorder(a, n, 2 * i + 2);
    printf("%d ", a[i]);
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

    postorder(a, n, 0);

    return 0;
}
