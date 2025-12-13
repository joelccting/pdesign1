#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int cnt = 0;
    scanf("%d", &x);

    for (int i = 1; i * i <= x; ++i)
    {
        if (x % i == 0) cnt += 2;
        if (i * i == x) cnt -= 1;
    }

    printf("%d", cnt);

    return 0;
}
