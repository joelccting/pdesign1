/**
 * version 1.0
 * Result: timelimit
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define dbg(fmt, args...) printf("[%d] " fmt, __LINE__, ##args)
#define dbg(fmt, args...)

typedef unsigned long long ULL;

ULL houseRobber(int *coin, int size)
{
    ULL sel = 0, nsel = 0;

    dbg("size=%d\n", size);
    if (size == 0) return 0;
    if (size == 1) return coin[0];

    /* if coin[size-1] is selected */
    sel += coin[size - 1] + houseRobber(coin, size - 2);

    /* if coin[size-1] is NOT selected */
    nsel += houseRobber(coin, size - 1);

    if (sel > nsel) return sel;

    return nsel;
}

int main()
{
    int nHouses;
    scanf("%d", &nHouses);

    int *coin = (int *) malloc(sizeof(int) * nHouses);
    memset(coin, 0, sizeof(int) * nHouses);

    for (int i = 0; i < nHouses; ++i) {
        scanf("%d", coin + i);
    }

    printf("%llu", houseRobber(coin, nHouses));

    free(coin);
    return 0;
}
