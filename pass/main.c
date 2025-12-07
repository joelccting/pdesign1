#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int g1, g2;
    double sum;

    scanf("%d %d", &g1, &g2);
    sum = 0.3 * g1;
    sum += 0.2 * g2;
    printf("%d", (int)ceil((60 - sum) * 2));
    return 0;
}

// my homework
//
//int main()
//{
//    int quiz, homework;
//    float test;
////    printf("Hello world!\n");
//
//    scanf("%d %d", &quiz, &homework);
//    test = 60 - 0.3 * quiz - 0.2 * homework;
//    test *= 4;
//    test /= 2;
//
//    if (((int)test * 2 * 0.25 + 0.3 * quiz + 0.2 * homework) < 60)
//        test += 1;
//
//    printf("%d", (int)test);
//
//    return 0;
//}

// reference answer
//int main(){
//    int a, b, x;
//    scanf("%d %d", &a, &b);
//    x = 6000 - a * 30 - b * 20;
//    printf("%d", x / 50 + (x % 50 > 0));
//}
