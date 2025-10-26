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
 */
 unsigned setPrime(char *isPrime, unsigned x)
 {
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i <= x; ++i)
    {
            isPrime[i] = 1;
    }

    for (int i = 2; i <= x; i++)
    {
        if (numOfFactors(i) != 2)
        {
            isPrime[i] = 0;
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

    return ret;
 }

 unsigned sumTwinPrime(char *isPrime, unsigned x)
 {
     unsigned ret = 0;

    for (int i = 4; i <= x; ++i)
    {
        if ((isPrime[i - 2] == 1) && (isPrime[i] == 1))
        {
            //printf("(%d, %d)\n", i, i + 2);
            ret++;
        }
    }

    return ret;
 }


int main()
{
    unsigned x, cnt = 0;

    scanf("%u", &x);

#if 0 /* test malloc */
    for (int i = 200; i < x; ++i)
    {
        void *p = malloc(sizeof(char) * i);
        if (!p)
        {
            printf("%d failed!\n", i);
            break;
        }

        printf("%d succeeded!\n", i);
        free(p);
    }
#endif

#if 1

    char *isPrime = (char *) malloc(sizeof(char) * x + 1);

    cnt = setPrime(isPrime, x);
    printf("Prime: %u\n", cnt);

    cnt = sumTwinPrime(isPrime, x);
    printf("Twin prime: %u\n", cnt);

    free(isPrime);
#endif
    return 0;
}
