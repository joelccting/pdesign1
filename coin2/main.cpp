//1212 coin
#include <iostream>

using namespace std;

int main()
{
    unsigned long long n, res, cnt = 0;

    cin >> n;

    cnt += n / 50;
    res = n % 50;
    cnt += res / 10;
    res %= 10;
    cnt += res / 5;
    res %= 5;
    cnt += res;

    cout << cnt;


    return 0;
}
