#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define SZ (1002)

void inorder(int a[], int i)
{
    if (a[2 * i + 1] > -1)
    {
        inorder(a, 2 * i + 1);
    }
    printf("%d ", a[i]);
    if (a[2 * i + 2] > -1)
    {
        inorder(a, 2 * i + 2);
    }
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

    inorder(a, 0);

    return 0;
}
