#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define DBG (1)

using namespace std;
typedef unsigned long long ULL;

int main()
{
    int n, x, tmp, cnt = 0;
    cin >> n >> x;
    vector<int> arr;
    vector<ULL> arrle, arrri;
    multiset<ULL> ms;

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    //for (int i = 0; i < n; ++i) cout << arr[i] << endl;

    for (int mask = 0; mask < (1 << (n / 2)); ++mask)
    {
        ULL sum = 0;
        for (int i = 0; i < n / 2; ++i)
        {
            if (mask & (1 << i))
            {
                sum += arr[i];
            }
        }
        arrle.push_back(sum);
    }

#if DBG
    for (ULL i : arrle) cout << i << " ";
        cout << "\n";
#endif // DBG

    for (int mask = 0; mask < (1 << (n - n/2)); ++mask)
    {
        ULL sum = 0;
        for (int i = 0; i < (n - n/2); ++i)
        {
            if (mask & (1 << i))
            {
                sum += arr[i + n / 2];
            }
        }
        arrri.push_back(sum);
    }

//    for (ULL x : arrri)
//    {
//        cout << x << " ";
//        cout << "\n";
//    }

    for (ULL i : arrri)
    {
        ms.insert(i);
    }

#if DBG
    cout << "multiset" << "\n";
    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << "\n";
#endif

    for (ULL i : arrle)
    {
        if (ms.end() != ms.find(x - i)) ++cnt;
    }

    cout << cnt;

    return 0;
}
