#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    int *a = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
    }

//    for (int i = 0; i < n; ++i)
//    {
//        printf("%d,", a[i]);
//    }
//    printf("\n");

    m %= n;

    for (int i = n - m; i < n; ++i)
    {
        printf("%d ", a[i]);
    }

    for (int i = 0; i < n - m; ++i)
    {
        printf("%d ", a[i]);
    }

    free(a);

    return 0;
}
