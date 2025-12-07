#include <stdio.h>
#include <stdlib.h>

int sec(int h, int m, int s)
{
    return ((h * 60) + m) * 60 + s;

}

int main()
{
    int h1, m1, s1, h2, m2, s2;

    scanf("%d %d %d", &h1, &m1, &s1);
    scanf("%d %d %d", &h2, &m2, &s2);

    printf("%d", abs(sec(h1, m1, s1) - sec(h2, m2, s2)));

    return 0;
}
