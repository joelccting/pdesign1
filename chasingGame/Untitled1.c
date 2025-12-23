#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);

        if (a == b) { // 若a == b，則至少消耗0張卡牌
            printf("0\n");
            continue;
        }
        if (a == 0 || b == 0 || b % a != 0) { // 若b % a != 0 ，代表b不是a的倍數
            printf("-1\n");
            continue;
        }

        long long ratio = b / a;
        int count = 0;
        int primes[3] = {2, 3, 5};// 不一定需要用到陣列

        for (int i = 0; i < 3; i++) { // 先把b/a中的質因數2,3,5剔除
            while (ratio % primes[i] == 0) {
                ratio /= primes[i];
                count++;
            }
        }

        if (ratio != 1) // ratio不等於1，代表b/a含有除了2,3,5之外的因數，只靠2,3,5不夠
            printf("-1\n");
        else
            printf("%d\n", count);
    }

    return 0;
}
