#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1
#define dbg(fmt, arg ...) do {if (DEBUG) printf("[%d] "fmt, __LINE__, ##arg);} while (0)

void reverse(char *a, int size)
{
        for (int i = 0; i < size / 2; ++i)
        {
            char tmp = a[i];
            a[i] = a[size - 1 - i];
            a[size - 1 - i] = tmp;
        }
}

void print(char *res, int len)
{
    int idx = len - 1;
    while (res[idx] == 0)
    {
        --idx;
    }

    for (int i = idx; i > -1; --i)
    {
        printf("%c", res[i] + '0');
    }
}

void add(char *n, char *m, char *res, int max)
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

void add2(char *des, char *m, int max)
{
    for (int i = 0; i < max; ++i)
    {
        if (des[i] + m[i] < 10)
        {
            des[i] += m[i];
        }
        else
        {
            des[i] = (des[i] + m[i] - 10);
            des[i + 1] += 1;
        }
    }
}

void mul(char *n, int sn, char *m, int sm, char *res, int max)
{
    char *tmp = (char *) malloc(sizeof(char) * (sn + sm));
    char *tmp2 = (char *) malloc(sizeof(char) * (sn + sm));
    memset(tmp2, 0, sn + sm);

    for (int i = 0; i < sm; ++i)
    {
        for (int j = 0; j < sn; ++j)
        {
            memset(tmp, 0, sn + sm);
            char mul = n[j] * m[i];
            int k = i + j;
            while (mul)
            {
                tmp[k] = mul % 10;
                if (tmp[k] > 9)
                {
                    tmp[k] %= 10;
                    tmp[k+1] = 1;
                }
                mul /= 10;
                k++;
            }
//            print(tmp, sn + sm); printf("\n");
            add2(tmp2, tmp, sn+sm);
//            printf("sum:"); print(tmp2, sn + sm); printf("\n");
        }
    }

    memcpy(res, tmp2, max);

    free(tmp);
}


int main()
{
    char t;

    int a, b, max, min;
    char *n, *m, *res, sign;

    scanf("%d %d", &a, &b);

    /* init */
    max = (a >= b) ? a : b;
    min = (a >= b) ? b : a;

    n = (char *) malloc(sizeof(char) * (a + 1));
    m = (char *) malloc(sizeof(char) * (b + 1));

    memset(n, 0, a + 1);
    memset(m, 0, b + 1);

    for (int i = a - 1; i > -1; --i)
    {
        scanf(" %c", &t);
        n[i] = t - '0';
    }

    for (int i = b - 1; i > -1; --i)
    {
        scanf(" %c", &t);
        m[i] = t - '0';
    }

    scanf(" %c", &sign);

    if (sign == '+')
    {
        res = (char *) malloc(sizeof(char) * (max + 1));
        memset(res, 0, max + 1);

        //add(n, m, res, max);
        add2(res, n, max + 1);
        add2(res, m, max + 1);
        print(res, max + 1);

    }

    if (sign == '*')
    {
        res = (char *) malloc(sizeof(char) * (a + b));
        memset(res, 0, a + b);

        mul(n, a, m, b, res, a + b);
        print(res, a + b);

    }



    free(res);
    free(n);
    free(m);

    return 0;
}
