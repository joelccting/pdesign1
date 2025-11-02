#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *a, int size)
{
        for (int i = 0; i < size / 2; ++i)
        {
            char tmp = a[i];
            a[i] = a[size - 1 - i];
            a[size - 1 - i] = tmp;
        }
}

int main()
{
    char t;

    int a, b, sign, max, min;
    char *n, *m, *res;

    scanf("%d %d", &a, &b);

    if (a >= b)
    {
        max = a;
        min = b;
        n = (char *) malloc(sizeof(char) * (a + 1));
        m = (char *) malloc(sizeof(char) * (a + 1));
        for (int i = 0; i <= a; ++i)
        {
            n[i] = 0;
            m[i] = 0;
        }
    }
    else
    {
        max = b;
        min = a;
        n = (char *) malloc(sizeof(char) * (b + 1));
        m = (char *) malloc(sizeof(char) * (b + 1));
        for (int i = 0; i <= b; ++i)
        {
            n[i] = 0;
            m[i] = 0;
        }
    }
    res = (char *) malloc(sizeof(char) * (a + b + 2));
    for (int i = 0; i < a+b+2; ++i) res[i] = 0;
//    printf("init done\n");

    for (int i = 0; i < a; ++i)
    {
        scanf(" %c", &t);
        n[i] = t - '0';
    }

    for (int i = 0; i < b; ++i)
    {
        scanf(" %c", &t);
        m[i] = t - '0';
    }

    scanf(" %c", &sign);

    reverse(n, a);
    reverse(m, b);
#if 1 //debug
    for (int i = 0; i < a; ++i)
    {
        printf("%d", n[i]);
    }
    printf("\n");
    for (int i = 0; i < b; ++i)
    {
        printf("%d", m[i]);
    }
    printf("\n");

    printf("%c, %d\n", sign, sign);
    printf("%d\n", '+');
#endif

    if (sign == '+')
    {
        for (int i = 0; i < max; ++i)
        {
            if (n[i] + m[i] < 10)
            {
                res[i] += (n[i] + m[i]);
            }
            else
            {
                res[i] += (n[i] + m[i] -10);
                res[i + 1] += 1;
            }
        }
    }

    if (sign == '*')
    {

    }

    for (int i = 0; i < a + b + 2; ++i)
        printf("%d", res[i]);

    free(n);
    free(m);
    free(res);

    return 0;
}
