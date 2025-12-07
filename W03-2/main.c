#include <stdio.h>
#include <stdlib.h>

int main()
{
//    printf("Hello world!\n");

    int a[2], b[2], c[2];
    int i;
    long long det[3], lhs, rhs;

    for (i = 0; i < 2; ++i)
    {
        scanf("%i %i %i", &(a[i]), &(b[i]), &(c[i]));
    }

    det[0] = det[1] = det[2] = 0;
    lhs = a[0];
    lhs *= b[1];
    rhs = a[1];
    rhs *= b[0];
    det[0] = lhs - rhs;

    lhs = a[0];
    lhs *= c[1];
    rhs = a[1];
    rhs *= c[0];
    det[1] = lhs - rhs;

    lhs = b[0];
    lhs *= c[1];
    rhs = b[1];
    rhs *= c[0];
    det[2] = lhs - rhs;

    if (det[0] != 0) /* one solution */
    {
        printf("YES");
    }
    else
    {

        if ((det[1] == 0) && (det[2] == 0)) /* infinite solution */
        {
            //printf("%d\n", __LINE__);
            printf("YES");
        }
        else /* no solution */
        {
            printf("NO");
        }

    }


    return 0;
}

//這一題主要是用到國中學到的如何判斷直線狀態。需要注意的是因為除法可能導致精度下降，等於的判斷會出錯原本 a1 / b1 == a2 / b2 要換成 a1 * b2 == a2 * b1。還需要注意由於這題數字到 10^9 ，直接乘會overflow需要開long long。


// SAMPLE　CODE
//#include <stdio.h>

//int main()
//{
//    long long a1, b1, c1;
//    long long a2, b2, c2;
//    scanf("%lld%lld%lld", &a1, &b1, &c1);
//    scanf("%lld%lld%lld", &a2, &b2, &c2);
//    if(a1 * b2 == a2 * b1) // 判斷兩線斜率是否相等
//    {
//        if(c1 * a2 == c2 * a1 && c1 * b2 == c2 * b1) // 判斷兩線重和或平行
//        {
//            printf("YES\n");
//        }
//        else
//        {
//            printf("NO\n");
//        }
//    }
//    else
//    {
//        printf("YES\n");
//    }
//}

// SAMPLE　CODE

//#include <stdio.h>

//int main(){
//    long long a1, b1, c1, a2, b2, c2;
//    scanf("%lld %lld %lld", &a1, &b1, &c1);
//    scanf("%lld %lld %lld", &a2, &b2, &c2);
//    long long D = a1*b2 - a2*b1, C1 = a1*c2 - a2*c1, C2 = b1*c2 - b2*c1;
//    D  %= (int)1e9 +7;
//    C1 %= (int)1e9 +7;
//    C2 %= (int)1e9 +7;
//    C1 = 2 * (C1 * C1) / (C1 * C1 + 1);
//    C2 = 2 * (C2 * C2) / (C2 * C2 + 1);
//    long long f = ((2 * (D * D) / (D * D + 1) + 1) % 2) * ((C1 + C2) / 2 + (C1 + C2) % 2);
//    int ans = 0;
//    ans = 896983 * (1 - f) + 787932 * f ;
//    printf("%c", ans / 10000);
//    ans %= 10000;
//    printf("%c", ans / 100);
//    ans %= 100;
//    printf("%c", ans);
//    return 0;
//}
