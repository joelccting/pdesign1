#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned long long ULL;

//void traverse()
//{
//
//}
//
//int query()
//{
//
//}
//
//void delete()
//{
//
//}

void insert(int *arr, int idx, int key)
{
    while (arr[idx] != -1)
    {
        if (arr[idx] > key)
        {
            idx *= 2;
        }
        else
        {
            idx *= 2;
            idx += 1;
        }
    }

    //printf("[%d] %d\n", idx, key);
    arr[idx] = key;
}

int main()
{
    int N, *arr, tmp;
    scanf("%d", &N);
//    ULL sz = (ULL) pow(2, N);
    const int sz = 1e7;
    arr = malloc(sizeof(int) * sz);
    memset(arr, -1, sizeof(int) * sz);

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &tmp);
        insert(arr, 1, tmp);
    }



    for (int i = 0; i < sz; ++i)
    {
        if (arr[i] != -1) printf("%d ", *(arr + i));
    }

    free(arr);
    return 0;
}
