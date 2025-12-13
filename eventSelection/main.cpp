//1212 eventSelection
#include <iostream>
#include <algorithm>

using namespace std;

struct Activity
{
    int s;
    int e;
};

bool compare(Activity a, Activity b)
{
    return a.e < b.e;
}

int main()
{
    int n, now, cnt = 0;
    cin >> n;
    Activity a[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].s >> a[i].e;
    }

    sort(a, a + n, compare);

    now = a[0].e;
    cnt++;

    for (int i = 1; i < n; ++i)
    {
        if (a[i].s >= now)
        {
            now = a[i].e;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
