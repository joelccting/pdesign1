#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    char *p = (char *) malloc(sizeof(char) * (n + 1));

    /* init */
    for (i = 0; i <= n; ++i)
    {
        if ((i % 2) == 1) p[i] = 1;
        else p[i] = 0;
    }

    i = n;
    while (p[i])
    {

    }

    for (int)
    free(p);

    return 0;
}
