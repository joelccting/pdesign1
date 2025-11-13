// Big number minus
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//des must be larger than src
void minus(char *des, char *src, int max)
{
//    print(des, max); printf("\n");
//    print(src, max); printf("\n");
    for (int i = 0; i < max; ++i)
    {
        //printf("[%d] %d %d\n", i, des[i], src[i]);
        if (des[i] >= src[i])
        {
            des[i] -= src[i];
        }
        else
        {
            int j = i + 1;
            while (des[j] == 0)
            {
                des[j] = 9;
                ++j;

            }
            des[j] -= 1;

            des[i] += 10;
            des[i] -= src[i];
        }

        //print(des, max); printf("\n");
        //printf("des[%d]=%d\n", i, des[i]);
    }
}

int compare(char *des, char *src, int len)
{
    for (int i = len - 1; i > -1; --i)
    {
        if (des[i] > src[i]) return 1;
        else if (des[i] < src[i]) return -1;
    }

    return 0;
}

int main()
{
    int n, m, max, min; // digits of a and b
    char *a, *b, ch;
    scanf("%d %d", &n, &m);

    max = (n >= m) ? n : m;
    min = (n >= m) ? n : m;

    a = (char *) malloc(sizeof(char) * max);
    b = (char *) malloc(sizeof(char) * max);
    memset(a, 0, max);
    memset(b, 0, max);

    for (int i = n - 1; i > -1; --i)
    {
        scanf(" %c", &ch);
        a[i] = ch - '0';
    }

    for (int i = m - 1; i > -1; --i)
    {
        scanf(" %c", &ch);
        b[i] = ch - '0';
    }

    //printf("sign:%d\n", compare(a, b, max));
    int isLarger = compare(a, b, max);
    switch (isLarger)
    {
        case 1:
            minus(a, b, max);
            print(a, max);
            break;

        case -1:
            minus(b, a, max);
            printf("-");
            print(b, max);
            break;

        case 0:
        default:
            printf("0");
            break;
    }

    free(a);
    free(b);

    return 0;
}
