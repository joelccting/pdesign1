#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Moviegoers
{
    int from;
    int to;
};

bool cmp(Moviegoers a, Moviegoers b)
{
    return (a.to < b.to);
}

int main()
{
    vector<Moviegoers> v;
    int total;

    cin >> total;

    while (total)
    {
        Moviegoers c;

        cin >> c.from >> c.to;
        v.push_back(c);
        --total;
    }

    sort(v.begin(), v.end(), cmp);

/*
    for (unsigned i = 0; i < v.size(); ++i)
    {
        cout << v[i].from << "," << v[i].to << "\n";
    }
*/

    int now = -1, cnt = 0;
    for (unsigned i = 0; i < v.size(); ++i)
    {
        if (now <= v[i].from)
        {
            now = v[i].to;
            ++cnt;
        }
    }

    cout << cnt;

    return 0;
}
