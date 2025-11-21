#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define dbg(fmt, args...) printf("[%d] " fmt, __LINE__, ##args)
#define dbg(fmt, args...)

typedef unsigned long long ULL;

/**
 * version 1.0
 * Result: TIMELIMIT
 */

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

/**
 * version 2.0
 * Result: CORRECT
 */

ULL houseRobber_v2(int *coin, int size)
{
    ULL sel = 0, nsel = 0;

    /* coin[size-1] and coin[size-2] must not be simultaneously selected */
    sel = coin[size - 1];
    nsel = (coin[size - 1] > coin[size - 2]) ? coin[size - 1] : coin[size - 2];

    for (int i = size - 3; i > -1; --i) {
        ULL rob = sel + coin[i];
        ULL skip = nsel;

        ULL curr = ((rob > skip) ? rob : skip);
        sel = nsel;
        nsel = curr;
        dbg("sel=%llu, nsel=%llu\n", sel, nsel);
    }

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

    //printf("%llu", houseRobber(coin, nHouses));
    printf("%llu", houseRobber_v2(coin, nHouses));

    free(coin);
    return 0;
}
