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

    int n, asize, q, tmp, t, from, to, mid = 0;
    vector<int> ev;

    cin >> asize >> q;

    n = asize;
    while (n)
    {
        cin >> tmp;
        ev.push_back(tmp);
        n--;
    }

    sort(ev.begin(), ev.end(), cmp);

    while (q)
    {
        cin >> t;
        from = 0;
        to = asize - 1;
        while (from <= to)
        {
            mid = from + (to - from) / 2; //avoid overflow
            if (ev[mid] == t) break;
            else if (ev[mid] < t) from = mid + 1;
            else to = mid - 1;
        }

//        cout << "mid[" << mid << "]=" << ev[mid] << "\n";

        if (ev[mid] == t)
        {
            cout << ev[mid];
        }
        else if (ev[mid] > t)
        {
            if ((mid - 1) < 0)
            {
                cout << ev[0];
            }
            else
            {
    //            cout << "L=" << mid <<"\n";
                if ((ev[mid] - t) >= (t - ev[mid - 1]))
                    cout << ev[mid - 1];
    //            else if ((ev[mid] - t) > (t - ev[mid - 1]))
    //                cout << ev[mid - 1];
                else
                    cout << ev[mid];
            }

        }
        else //(ev[mid] < t)
        {
            if ((mid + 1) >= asize)
            {
                cout << ev[mid];
            }
            else
            {
    //            cout << "mid=" << mid <<"\n";
                if ((ev[mid + 1] - t) >= (t - ev[mid]))
                    cout << ev[mid];
    //            else if ((ev[mid + 1] - t) > (t - ev[mid]))
    //                cout << ev[mid];
                else
                    cout << ev[mid + 1];
            }
        }

        cout << " ";

        q--;
    }

    return 0;
}
