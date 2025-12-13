#include <stdio.h>
#include <stdlib.h>

int f(int x)
{
    if (x == 1) return 1;

    if (x % 4 == 0) return f(x / 4);

    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("false");
    }
    else
    {
        if (f(n)) printf("true");
        else printf("false");
    }
    return 0;
}

// My previous homework
//
//    while (n > 1) {
//        r = n % 4;
//        if (r) break;
//        n /= 4;
//    }
//
//    if (r == 0)
//    {
//        printf("true");
//    }
//    else
//    {
//        printf("false");
//    }

//若 n ≤ 0 直接輸出 false；否則不停地把 n 除以 4，只要餘數不是 0 就不是 4 的冪。最後若能剛好降到 1，代表是 4 的冪。
//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    long long n;
//    scanf("%lld", &n);
//
//    if (n <= 0) {
//        printf("false");
//        return 0;
//    }
//
//    while (n % 4 == 0) {
//        n /= 4;
//    }
//    if(n==1){
//        printf("true");
//    }else{
//        printf("false");
//    }
//    return 0;
//}
