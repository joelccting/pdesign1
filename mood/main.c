#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, begin, end;
    char *a;
    int *sum;

    scanf("%d", &n);

    a = malloc(sizeof(char) * n);
    sum = malloc(sizeof(int) * (n + 1));
    memset(a, 0, sizeof(char) * n);
    memset(sum, 0, sizeof(int) * (n + 1));

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
        sum[i + 1] += sum[i] + a[i];
    }

#if 0
    for (int i = 0; i < n + 1; ++i)
    {
        printf("%d ", sum[i]);
    }
    printf("\n");
#endif

    while (scanf("%d %d", &begin, &end) != EOF)
    {
//        if ((begin == 1) && (end == n))
//        {
//            //printf("s: ");
//            printf("%d\n", sum);
//            continue;
//        }
#if 0
        sum = 0;
        for (int i = begin; i <= end; ++i)
        {
            sum += a[i];
        }
#endif
        /* «eºó©M */

        printf("%d\n", sum[end] - sum[begin - 1]);
    }

    free(a);
    free(sum);

    return 0;
}
