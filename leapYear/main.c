#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    unsigned y;

    scanf("%u", &y);

    bool y1 = (y % 4 == 0);
    bool y2 = (y % 100 == 0);
    bool y3 = (y % 400 == 0);

    if (y1)
    {
        if (y2 && !y3) printf("NO");
        else printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
