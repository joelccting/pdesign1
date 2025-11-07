#include <stdio.h>
#include <stdlib.h>

#define SIZE (100)

int binarySearch(int *a, int from, int to, int key)
{
    if (from > to) return -1;

    int av = (from + to) / 2;

    if (a[av] == key) return av;
    else if (a[av] < key) return binarySearch(a, av+1, to, key);
    else /*if (a[av] > key)*/ return binarySearch(a, from, av-1, key);

    return -1;
}

int interSearch(int *a, int n, int from, int to, int key)
{
    if (from > to) return -1;

    int av = from + (key - a[from]) * (to - from) / n;
    if (a[av] == key) return av;
    else if (a[av] < key) return interSearch(a, n, av+1, to, key);
    else /*if (a[av] > key)*/ return interSearch(a, n, from, av-1, key);
    return -1;
}

int main()
{
    int array[SIZE];

    //scanf()

    for (int i = 0; i < SIZE; ++i)
    {
        array[i] = 2 * i;
    }

    printf("index=%d\n", binarySearch(array, 0, 99, 64));
    printf("index=%d\n", binarySearch(array, 0, 99, 63));
    printf("--------------\n");
    int av, res = -1, obj = 64, from = 0, to = 99;
    while (from <= to)
    {
        av = (from + to) / 2;
        printf("%d-%d\n", from, to);

        if (array[av] == obj)
        {
            res = av;
            break;
        }
        else if (array[av] < obj)
        {
            to = av - 1;
        }
        else //(a[av] < obj)
        {
            from = av + 1;
        }

        if (from > to) break;
    }
    printf("res=%d\n", res);

    printf("---interSearch---\n: %d\n: %d\n", interSearch(array, SIZE, 0, 99, 64)
           , interSearch(array, SIZE, 0, 99, 63));

    return 0;
}
