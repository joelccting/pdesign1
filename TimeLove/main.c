#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%.2f", ((double) x) / y);
    return 0;
}
