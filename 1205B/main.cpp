// 1205B

#include <iostream>

using namespace std;
typedef unsigned long long ULL;

int main()
{
    int n, x, cnt = 0;
    cin >> n >> x;

    ULL a[n];

    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int mask = 0; mask < (1 << n); ++mask)
    {
        ULL sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                sum += a[i];
            }
        }

        if (x == sum) ++cnt;
    }

    cout << cnt << endl;

    return 0;
}
