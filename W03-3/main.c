#include <stdio.h>
#include <stdlib.h>

int main()
{
    int month[2], date[2];
    unsigned long long tmp = 0;
    int i;

    for (i = 0; i < 2; ++i)
    {
        scanf("%d %d", &(month[i]), &(date[i]));
        tmp += month[i];
        tmp += date[i];
    }

    tmp += 567;
    tmp *= 105;
    tmp += 28;
    tmp *= 39;
    tmp -= 76;
    tmp %= 455;
    tmp *= 49069;

    printf("%llu", tmp);

//    printf("Hello world!\n");

    return 0;
}


//直接照著公式算，或者注意到 455 = 5 * 7 * 13，105 = 3 * 3 * 5 * 7，39 = 3 * 13，原本的數字乘上 105 和 39 之後會被約掉，所以原本不管輸入什麼答案都會一樣。
//#include <stdio.h>
//
//int main()
//{
//    printf("5201314");
//}
