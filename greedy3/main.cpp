//工作排程3- 最小平均等待時間
//有n個工作從開始就進入到機器，給予n個工作的執行需要的時間，
//只有一台機器可以執行，每次只能執行一個工作，且工作開始做就需要做完，機器執行中不能跳到另一個工作，
//Q:請計算完成所有工作所需要的最小平均等待時間？

//貪婪準則是最少執行時間的工作優先執行。由小到大排序所工作的執行時間，執行時間越短的工作越優先執行，最後統計每個工作的等待時間，計算平均等待時間就可獲得最小平均等待時間。

#include <iostream>
#include <algorithm>

bool cmp(int a, int b)
{
    return a < b;
}

using namespace std;

int main()
{
    int n, waitTime = 0;
    double sum = 0;

    cin >> n;
    int taskLen[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> taskLen[i];
    }

    sort(taskLen, taskLen + n, cmp);

    for (int i = 1; i < n; ++i)
    {
        waitTime = 0;
        for (int j = 0; j < i; ++j)
        {
            waitTime += taskLen[j];
        }

        cout << "task " << i << " wait " << waitTime << "\n";
        sum += waitTime;
    }


    cout << sum / n << "\n";

    return 0;
}
