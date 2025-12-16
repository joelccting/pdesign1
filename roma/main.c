#include <stdio.h>
#include <stdlib.h>
// I=1,V =5,X=10,L=50,C=100,D=500,M =1000

const char *str1[] = {
    "",
    "I",
    "II",
    "III",
    "IV",
    "V",
    "VI",
    "VII",
    "VIII",
    "IX"
};

const char *str2[] = {
    "",
    "X",
    "XX",
    "XXX",
    "XL",
    "L",
    "LX",
    "LXX",
    "LXXX",
    "XC"
};

const char *str3[] = {
    "",
    "C",
    "CC",
    "CCC",
    "CD",
    "D",
    "DC",
    "DCC",
    "DCCC",
    "CM"
};

const char *str4[] = {
    "",
    "M",
    "MM",
    "MMM"
};

void proma(int d4, int d3, int d2, int d1)
{
    printf("%s", str4[d4]);
    printf("%s", str3[d3]);
    printf("%s", str2[d2]);
    printf("%s", str1[d1]);
}

int main()
{
    int n;
    int i, x, l, c, d, m;

    scanf("%d", &n);
    int d1, d2, d3, d4;
    d4 = n / 1000;
    d3 = (n - d4 * 1000) / 100;
    d2 = (n - d3 * 100 - d4 * 1000) / 10;
    d1 = n - d2 * 10 - d3 * 100 - d4 * 1000;
#if 0
    printf("%d %d %d %d\n", d4, d3, d2, d1);
#endif

//    for (int i = 0; i < d1k; ++i) printf("M");
//    for (int i = 0; i < d100; ++i) printf("C");
//    for (int i = 0; i < d10; ++i) printf("X");
//    for (int i = 0; i < d1; ++i) printf("I");

    proma(d4, d3, d2, d1);
    return 0;
}
