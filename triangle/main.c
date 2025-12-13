#include <stdio.h>
#include <stdlib.h>

int main()
{
    int type, n;
    while (scanf("%d %d", &type, &n) != EOF)
    {
        if (type) //upside-down triangle
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = n - i; j > 0; --j)
                {
                    printf("%d ", j);
                }
                printf("\n");
            }
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = i + 1; j > 0; --j)
                {
                    printf("%d ", j);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
