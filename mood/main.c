#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, begin, end;
    int sum = 0;
    //char *a;
    scanf("%d", &n);
    int a[n + 1];

//    a = (char *) malloc(sizeof(char) * (n+1));
    for (int i = 0; i <= n; ++i)
    {
        a[i] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &(a[i]));
//        sum += a[i];
    }

    while (scanf("%d %d", &begin, &end) != EOF)
    {
//        if ((begin == 1) && (end == n))
//        {
//            //printf("s: ");
//            printf("%d\n", sum);
//            continue;
//        }

        sum = 0;
        for (int i = begin; i <= end; ++i)
        {
            sum += a[i];
        }
        printf("%d\n", sum);
    }

//    free(a);

    return 0;
}
