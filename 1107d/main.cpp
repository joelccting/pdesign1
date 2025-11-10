#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> qu;

    for (int i = 1; i <= n; ++i)
        qu.push(i);

//        cout << qu.size() << endl;

    while (qu.size())
    {
        int tmp = qu.front();
        qu.pop();
        qu.push(tmp);

        cout << qu.front() << " ";
        qu.pop();
    }


    return 0;
}
