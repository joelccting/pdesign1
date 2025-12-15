// v0.1 TIMELIMIT

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d", &n);

    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i < n + 1; ++i)
    {
        int tmp;
        scanf(" %d", &tmp);
        a[i] = tmp + a[i - 1];
    }

//    for (int i = 1; i < n + 1; ++i)
//    {
//        printf("%d,", a[i]);
//    }

    scanf("%d", &m);
    int q[m]; //printf("m=%d\n", m);

    for (int i = 0; i < m; ++i)
    {
        scanf(" %d", q + i);
    }

//    for (int i = 0; i < m; ++i)
//    {
//        printf("%d,", q[i]);
//    }

    for (int i = 0; i < m; ++i)
    {
        int j = 1; //printf("%d", q[i]);
        while ((q[i] < a[j - 1]) || (q[i] > a[j]))
        {
            ++j;
        }
        printf("%d\n", j);
    }




    return 0;
}
