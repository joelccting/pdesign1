#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DBG (0)

int lastRemaining(int n)
{
    unsigned head = 1;
    unsigned step = 1;
    bool toLargeNum = true;
    int remaining = n;

    while (remaining > 1)
    {
#if DBG
        printf("head=%d,step=%d, %s\n", head, step, toLargeNum ? "R" : "L");
#endif
        if (toLargeNum || (remaining & 0x1 == 1)) head += step;
        remaining /= 2;
        step *= 2;
        toLargeNum = !toLargeNum;
    }

    return head;
}

int main()
{
    int n, i;
    scanf("%d", &n);

    printf("%d", lastRemaining(n));

    return 0;
}
