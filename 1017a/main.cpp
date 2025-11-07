// 1017 problem A

#include <iostream>

using namespace std;

int main()
{
    int x, cnt = 0;

    cin >> x;

    for (int i = 1; (i * i) <= x; ++i)
    {
        if ((x % i) == 0)
        {
            cnt += 2;
        }

        if ((i * i) == x)
        {
            cnt -= 1;
        }
    }

    cout << cnt;

    return 0;
}
