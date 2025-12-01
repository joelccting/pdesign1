#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DBG (1)

#if DBG
#define dbg(s, b...) printf(s, ##b)
#else
#define dbg(s, b...)
#endif

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void permute(int arr[], int **des, int l, int r)
{
    static int k = 0;
    int i;

    if (l == r) {
        for (i = 0; i <= r; i++)
        {
            dbg("%d ", arr[i]);
            des[k][i] = arr[i];
        }
        ++k;
        dbg("\n");
        return;
    }

    for (i = l; i <= r; i++)
    {
        swap(&arr[l], &arr[i]);     /* put arr[i] at position l */
        permute(arr, des, l + 1, r);     /* recurse for next position */
        swap(&arr[l], &arr[i]);     /* backtrack */
    }
}

unsigned factorial(unsigned n)
{
    if (n == 1) return 1;

    return n * factorial(n - 1);
}

int cmpRecursive(int *x, int *y, int pos)
{
    if (pos == 3) return 0;

    if (x[pos] > y[pos]) return 1;
    else if (x[pos] < y[pos]) return -1;

    return cmpRecursive(x, y, pos + 1);
}

int cmp(const void *a, const void *b)
{
    int *x = *(int **)a;
    int *y = *(int **)b;

    return cmpRecursive(x, y, 0);
}

int main()
{
    int arr[] = {2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int msize = factorial(n); dbg("msize=%d\n", msize);

    int **b = malloc(msize * sizeof(int *));
    memset(b, 0, msize * sizeof(int *));

    for (int i = 0; i < msize; ++i)
    {
        b[i] = malloc(sizeof(int) * sizeof(arr));
        memset(b[i], 0, sizeof(int) * sizeof(arr));
    }

    permute(arr, b, 0, n - 1);

#if DBG
    dbg("before qsort\n");
    for (int i = 0; i < msize; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            dbg("%d ", b[i][j]);
        }
        dbg("\n");
    }
#endif

    qsort(b, msize, sizeof(int *), cmp);

#if DBG
    dbg("after qsort\n");
    for (int i = 0; i < msize; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            dbg("%d ", b[i][j]);
        }
        dbg("\n");
    }
#endif

    for (int i = 0; i < msize; ++i) free(b[i]);
    free(b);

    return 0;
}
