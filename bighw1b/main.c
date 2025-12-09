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
int query(int *arr, int key)
{
    int idx = 1;
    int ret = -1;

    while (arr[idx] != -1)
    {
        if (arr[idx] > key)
        {
            printf("%d L\n", arr[idx]);
            idx *= 2;
        }
        else if (arr[idx] < key)
        {
            printf("%d R\n", arr[idx]);
            idx = idx * 2 + 1;
        }
        else
        {
            printf("%d Done\n", arr[idx]);
            ret = idx;
            break;
        }
    }

    return ret;
}
//
//void delete()
//{
//
//}

void insert(int *arr, int key)
{
    int idx = 1;

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
    int N, M, *arr, key;
    scanf("%d %d", &N, &M);
//    ULL sz = (ULL) pow(2, N);
    const int sz = 1e7;
    arr = malloc(sizeof(int) * sz);
    memset(arr, -1, sizeof(int) * sz);

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &key);
        insert(arr, key);
    }

//    for (int i = 0; i < sz; ++i)
//    {
//        if (arr[i] != -1) printf("%d ", *(arr + i));
//    }

    for (int i = 0; i < M; ++i)
    {
        scanf("%d", &key);
        if (query(arr, key) < 0)
        {
            printf("Not found\n");
        }
    }

    free(arr);
    return 0;
}
