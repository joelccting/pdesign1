#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;

int main()
{
    ULL score = 0, credit = 0;
    ULL weightedSum = 0;
    ULL sumCredit = 0;
    double ans;


    for (int i = 0; i < 3; ++i)
    {
        scanf("%llu %llu", &score, &credit);
        weightedSum += score * credit;
        sumCredit += credit;
    }

    ans = (double) weightedSum / sumCredit;
    printf("%.2f", ans);
    return 0;
}

// my homework
//
//    unsigned score, credit;
//    unsigned long long sumScore = 0, sumCredit = 0;
//    double ans;
//
//    for (int i = 0; i < 3; ++i)
//    {
//        scanf("%u %u", &score, &credit);
//        sumScore += ((unsigned long long)score * credit);
//        sumCredit += (unsigned long long)credit;
//    }
//
//    ans = sumScore;
//    ans /= sumCredit;
//    printf("%.2f", ans);


//主要是考type casting
//此外，會使用double是因為double比float還要精確
//#include <limits.h>
//
//int main() {
//    int score, weight;
//    long long total_score = 0;
//    long long total_weight = 0;
//
//    for(int i = 0; i < 3; i++) {
//        scanf("%d %d", &score, &weight);
//        total_score += (long long)score * weight;
//        total_weight += weight;
//    }
//
//    double average = (double)total_score / total_weight;
//    printf("%.2lf\n", average);
//
//    return 0;
//}
