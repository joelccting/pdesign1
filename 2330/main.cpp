#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unsigned long long a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
//    for (int i = 0; i < n; ++i) cout << a[i] << endl;
    int flags = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                if ((i == j) || (j == k) || (i == k)) continue;

                if ((a[i] + a[j] + a[k]) % 10 == 0)
                {
                    ++flags;
                }
            }
        }
    }

    if (flags) cout << "YES";
    else cout << "NO";

    return 0;
}
