#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return (a < b);
}

int main()
{
    //io speed up
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, tmp;
    vector<int> ev;

    cin >> n >> k;

    while (n)
    {
        cin >> tmp;
        ev.push_back(tmp);
        n--;
    }

    sort(ev.begin(), ev.end(), cmp);

    int lhs = 0,
        rhs = ev[0] * k,
        mid, answer = 0;
        unsigned long long i;
    while (lhs <= rhs)
    {

        mid = lhs + (rhs - lhs) / 2;
        //cout << lhs << "," << mid << "," << rhs << "\n";
        int sum = 0;
        for (i = 0; i < ev.size(); ++i)
        {
            sum += mid / ev[i];

            if (sum > k)
            {
                break; //already qualified to do binary search
            }
        }

        if (sum == k)
        {
            answer = mid;
            break;
        }
        else if (sum > k)
        {
            rhs = mid - 1;
        }
        else // (sum < k)
        {
            lhs = mid + 1;
        }
    }

    cout << answer;

    return 0;
}
