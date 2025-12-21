// 助教課

#include <stdio.h>
long long arr[32];
long long int m,n;
long long isPrime(long long x)
{
    if (x < 2) return 0;
    for (long long i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

long long int Solve(int n, int mask)
{
    long long int count = 0;
    long long int ans = 1;
    long long int flag = 0;
    for (long long int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
        {
            ans *= arr[i];
            count++;
        }
    }

    if (count % 2 == 0) ans *= -1;
    if(flag)
        return 0;
    else
        return ans;
}

int main()
{
    int prime_count = 0;
    scanf("%lld",&m);
    scanf("%lld",&n);

    ///找出範圍內質數有哪些
    for(long long i = 2;i <= n ; i++)
    {
        if(isPrime(i))
        {
            arr[prime_count++] = i;
        }
    }

    long long int  total = m;
    for (long long mask = 1; mask < (1 << prime_count); mask++)
    {
        printf("mask:%lld\n", mask);
        long long tmp = Solve(prime_count, mask);
        if (tmp != 0)
        {
            total -= m / tmp;
        }
    }
    printf("%lld\n",total);
    return 0;
}
