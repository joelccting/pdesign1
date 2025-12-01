#include <stdio.h>
#include <stdlib.h>

#define dbg(s, b...) printf(s, ##b)

void printmx(unsigned **a, unsigned m, unsigned n)
{
    dbg("%s:\n", __func__);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%u ", a[i][j]);
        }

        printf("\n");
    }
}

void print(unsigned *a, unsigned size)
{
    //dbg("%s:\n", __func__);
    for (int i = 0; i < size; ++i) printf("%u ", a[i]);

    printf("\n");
}

int cmp(const void *a, const void *b)
{
    if (*(int *)a < *(int *)b) return -1;
    else if (*(int *)a > *(int *)b) return 1;
    return 0;
}

int mxcmp(const void *a, const void *b)
{
    int *x = (int *) a;
    int *y = (int *) b;
    if (x[0] < y[0]) return -1;
    else if (x[0] > y[0]) return 1;
    return cmp(&x[1], &y[1]);
}

void swap(unsigned *a, unsigned *b)
{
    unsigned tmp = *a;
    *a = *b;
    *b = tmp;
}

void permutate(unsigned *a, unsigned size, unsigned start, unsigned **b)
{
    static unsigned k = 0;

    if (size == start)
    {
        print(a, size);
        for (int i = 0; i < size; ++i) b[k][i] = a[i];
        ++k;
        return;
    }

    for (int i = start; i < size; ++i)
    {
        dbg("swap %d %d\n", i, start);
        swap(a + i, a + start);
        permutate(a, size, start + 1, b);
        swap(a + i, a + start);
    }
}

unsigned factorial(unsigned n)
{
    if (n == 1) return 1;

    return n * factorial(n - 1);
}

int main()
{
    unsigned nCnts, msize;

    nCnts = 3;
    //scanf("%u", &nCnts);
    unsigned a[] = {2, 1, 3};
    msize = factorial(nCnts);
    unsigned **b = malloc(sizeof(unsigned *) * msize);
    for (int i = 0; i < msize; ++i)
        b[i] = malloc(sizeof(unsigned) * nCnts);

//    for (int i = 0; i < nCnts; ++i)
//    {
//        scanf("%u", a + i);
//    }

    qsort(a, nCnts, sizeof(unsigned), cmp);

    permutate(a, nCnts, 0, b);

    //printmx(b, msize, nCnts);

    //qsort(b, msize, sizeof(b[0]), mxcmp);

    //printmx(b, msize, nCnts);

    for (int i = 0; i < msize; ++i) free(b[i]);
    free(b);

    return 0;
}
