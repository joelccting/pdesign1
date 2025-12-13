//1212 pointMatching

#include <iostream>
#include <algorithm>

using namespace std;

struct Person
{
    int sn;
    int pos;
    int lover;
};

bool cmp(Person a, Person b)
{
    return a.pos < b.pos;
}

bool cmp2(Person a, Person b)
{
    return a.sn < b.sn;
}

int main()
{
    int n;
    cin >> n;
    Person x[n], y[n];
    for (int i = 0; i < n; ++i)
    {
        x[i].sn = i + 1;
        cin >> x[i].pos;
    }

    for (int i = 0; i < n; ++i)
    {
        y[i].sn = i + 1;
        cin >> y[i].pos;
    }

    sort(x, x + n, cmp);
    sort(y, y + n, cmp);

    for (int i = 0; i < n; ++i)
    {
        x[i].lover = y[i].sn;
    }


    sort(x, x + n, cmp2);

    for (int i = 0; i < n; ++i) cout << x[i].lover << "\n";
    return 0;
}
