#include <stdio.h>
#include <stdlib.h>



int main()
{
    unsigned n;
    scanf("%u", &n);
    int a[n][n];
    int i = 0, j = 0;
    char turn;
    int rotate = 0;

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            scanf(" %d", &(a[i][j]));

    while (scanf(" %c", &turn) != EOF)
    {
        //printf("Got: %c\n", turn);
        if (turn == 'R') rotate--;
        if (turn == 'L') rotate++;
        //if (turn == 'o') break;
    }


    if (rotate > -1) {
            rotate %= 4;
    } else {
        while (rotate < 0) rotate += 4;
    }
    //printf("rotate %d\n", rotate);

    switch (rotate)
    {
    case 0:
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        break;
    case 1:
        for (int i = n - 1; i > -1; --i)
        {
            for (int j = 0; j < n; ++j)
            {
                printf("%d ", a[j][i]);
            }
            printf("\n");
        }
        break;
    case 2:
        for (int i = n - 1; i > -1; --i)
        {
            for (int j = n - 1; j > -1; --j)
            {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        break;
    case 3:
        for (int i = 0; i < n; ++i)
        {
            for (int j = n - 1; j > -1; --j)
            {
                printf("%d ", a[j][i]);
            }
            printf("\n");
        }
        break;
    }


    return 0;
}
