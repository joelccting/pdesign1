#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

unsigned getVal(char c)
{
    unsigned ret;
    if ((c>='0') && (c<='9'))
    {
        ret = (c-'0');
    }
    else
    {
        ret= (c-'a') + 10;
    }

//    printf("getVal: %d\n", ret);
    return ret;
}

unsigned getDigits(unsigned n, int a)
{
    unsigned ret = 1;
    while (n / a > 0)
    {
        n /= a;
        ++ret;
    }

    return ret;
}

int getMaxLen(unsigned base1, int len, unsigned base2)
{
    int ret = 0;

    return ret;
}

int main()
{
    int a, b, n;
    char out[32];

    memset(out, '0', sizeof(out));
    scanf("%d %d %d", &a, &b, &n);
    char *s = (char *) malloc(sizeof(char) * (n + 1));
    memset(s, 0, n+1);

    for (int i = n-1; i > -1; --i)
    {
        scanf(" %c", &(s[i]));
    }

    unsigned res = getVal(s[n-1]);
    for (int i = n-2; i >-1; --i)
    {
#if DEBUG
    printf("res=%u, a:%d\n", res, a);
#endif // DEBUG
        res *= a;
        res += getVal(s[i]);
    }
#if DEBUG
    printf("res=%u\n", res);
#endif // DEBUG

    int pos = 0;
    if (b <= 10)
    {
        while (res / b != 0)
        {
            out[pos++] = res % b + '0';
            res /= b;
        }

        out[pos] = res + '0';
    }
    else
    {
        while (res / b != 0)
        {
            if (res % b > 9)
            {
                out[pos++] = res % b - 10 + 'a';
            }
            else
            {
                out[pos++] = res % b + '0';
            }

            res /= b;
        }

        if (res % b > 9)
        {
            out[pos] = res % b - 10 + 'a';
        }
        else
        {
            out[pos] = res % b + '0';
        }
    }


#if 0
    for (int i = n-1; i > -1; --i)
    {
        printf("%c", s[i]);
    }
    printf("\n");
 #endif

 #if 1

    int i  = pos;
    while (out[i] == '0') ++i;
    while (i > -1)
    {
        printf("%c", out[i--]);
    }
    printf("\n");
 #endif


    free(s);
    return 0;
}
