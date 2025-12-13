#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;

int main()
{
    int n, k;
    ULL tmp, product = 1;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i)
    {
        scanf("%llu", &tmp);
        product *= tmp;
        product %= k;
    }

    printf("%llu", product);

    return 0;
}

//模運算在加法以及乘法上具有分配律，若單純在最後才mod，則因為result早已超出long long上限，其值已經錯誤，故每次
//(𝑟𝑒𝑠𝑢𝑙𝑡∗𝑥)都要先mod一次才不會超出
//    for (int i = 0; i < n; i++) {
//        scanf("%lld", &x);
//        result = (result * x) % k; // 防止溢位，邊乘邊取模
//    }
//
//    printf("%lld\n", result % k);
//    return 0;
