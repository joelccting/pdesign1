#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Customers
{
    int time;
    int isArrive;
};

bool cmp(Customers a, Customers b)
{
    return (a.time < b.time);
}

int main()
{

    vector<Customers> v;
    int total;

    cin >> total;

    while (total)
    {
        Customers c;

        c.isArrive = 1;
        cin >> c.time;
        v.push_back(c);

        c.isArrive = -1;
        cin >> c.time;
        v.push_back(c);
        --total;
    }

#if 0
    for (unsigned i = 0; i < v.size(); ++i)
    {
        cout << v[i].time << "," << v[i].isArrive << "\n";
    }
#endif

    sort(v.begin(), v.end(), cmp);

    int maxNum = 0, sum = 0;
    for (unsigned i = 0; i < v.size(); ++i)
    {
        sum += v[i].isArrive;
        if (sum > maxNum) maxNum = sum;
    }

    cout << maxNum;

    return 0;
}
