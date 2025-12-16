#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[200000] = {0};
    char s2[200000] = {0};
    int code1 = 0, code2 = 0;
    scanf("%s %s", s1, s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 > len2)
    {
        printf("You Lie");
        return 0;
    }
#if 0
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
#endif

//    char *p = strstr(s2, s1);
//    if (p)
//    {
//        printf("%d\n", p - s2);
//        return 0;
//    }

    for (int i = 0; i < len1; ++i) code1 += s1[i];
#if 0
    printf("code1=%d\n", code1);
#endif

    int j;
    int hit = 0;
    for (int i = 0; i < len2 - len1; ++i)
    {
        code2 = 0;
        for (j = i; j < i + len1; ++j)
        {
#if 0
            printf("%c,", s2[j]);
#endif
            code2 += s2[j];
        }
#if 0
        printf("code2=%d\n", code2);
#endif
        if (code2 == code1)
        {
            hit = 1;
            break;
        }

    }

    if (hit) printf("%d", j - len1);
    else printf("You Lie");

    return 0;
}
