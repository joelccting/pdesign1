//工作排程1-最多有幾個工作可以執行
//有n個工作可以執行，給定每個工作的開始時間與結束時間，時間從0開始，開始與結束時間都是整數，
//只有一台機器可以執行，每次只能執行一個工作，且工作開始做就需要做完，
//機器執行中不能跳到另一個工作，可以一結束就馬上接著執行另一個工作，機器更換工作很快，可以不考慮切換所需時間，
//Q:請計算執行完後最多有幾個工作被完成？



#include <iostream>
#include <algorithm>

using namespace std;

struct Job
{
    int s;
    int e;
};

bool cmp(Job a, Job b)
{
    if (a.s == b.s) return a.e < b.e;
    return a.s < b.s;
}



int main()
{
    int n, now = -1, ans = 0;

    cin >> n;
    Job jb[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> jb[i].s >> jb[i].e;
    }

    sort(jb, jb + n, cmp);
    for (int i = 0; i < n; ++i)
    {
        if (now <= jb[i].s)
        {
            ans++;
            now = jb[i].e;
            cout << ans << ": " << jb[i].s << "~" << jb[i].e << "\n";
        }
    }

    cout << ans << "\n";

    return 0;
}
