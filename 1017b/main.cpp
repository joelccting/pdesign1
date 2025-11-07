#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(int a, int b)
{
    //cout << a << "," << b << "\n";
    //if ((a > 0) && (b < 0)) return true;
    //else if ((a < 0) && (b > 0)) return false;
    return (a > b);
}

int main()
{
    int n, tmp;
    cin >> n;
    vector<int> ev, ov;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if ((tmp % 2) == 0) ev.push_back(tmp);
        else ov.push_back(tmp);
    }

    sort(ev.begin(), ev.end(), cmp);
    sort(ov.begin(), ov.end(), cmp);

    for (unsigned i = 0; i < ev.size(); i++)
    {
        cout << ev[i] << " ";
    }

    for (unsigned i = 0; i < ov.size(); i++)
    {
        cout << ov[i];
        if (i != (ov.size() - 1)) cout << " ";
    }

    return 0;
}
