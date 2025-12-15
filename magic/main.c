// v0.1 TIMELIMIT
// v0.2 CORRECT

#include <stdio.h>
#include <stdlib.h>

int search(int key, int *a, int from, int to)
{
    int mid;

    while (from <= to)
    {
        mid = (from + to) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (key < a[mid])
        {
            to = mid - 1;
        }
        else // (key > a[mid])
        {
            from = mid + 1;
        }
    }

//    printf("from=%d; to=%d\n", from, to);
    return from;
}

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

//    for (int i = 0; i < n + 1; ++i)
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

#if 0
    for (int i = 0; i < m; ++i)
    {
        int j = 1; //printf("%d", q[i]);
        while ((q[i] < a[j - 1]) || (q[i] > a[j]))
        {
            ++j;
        }
        printf("%d\n", j);
    }

#endif

    for (int i = 0; i < m; ++i)
    {
        printf("%d\n", search(q[i], a, 0, n));
    }



    return 0;
}
