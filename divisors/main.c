#include <stdio.h>
#include <stdlib.h>

/* Trial Division */
int numOfFactors(unsigned x)
{
    unsigned cnt = 0;

    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0) cnt += 2;
        if (x == (i * i)) cnt -= 1;
    }

    return cnt + 2;
}


/** Sieve of Eratosthenes
    ®J©Ô¦«´µ¯S¥§¿zªk
 */
 unsigned sieveOfEratosthenes(unsigned x)
 {
    char *isPrime = (char *) malloc(sizeof(char) * x + 1);

    for (int i = 1; i <= x; ++i)
    {
            isPrime[i] = 1;
    }

    for (int i = 2; i <= x * x; i++)
    {
        if (isPrime[i] == 0)
        {
            continue;
        }

        for (int j = i + i; j <= x; j += i)
        {
            if (isPrime[j] == 0) continue;

            isPrime[j] = 0;
        }
    }

    unsigned ret = 0;
    for (int i = 2; i <= x; ++i)
    {
        if (isPrime[i] == 1)
        {
            //printf("%02d\n", i);
            ++ret;
        }
    }

    free(isPrime);
    return ret;
 }


int main()
{
    unsigned x, cnt = 0;

    scanf("%u", &x);

    cnt = sieveOfEratosthenes(x);
    printf("%u", cnt);

    return 0;
}
