//工作排程2-最多有幾台機器一起運作
//有n個工作可以同時執行，給定每個工作的開始時間與結束時間，工作時間可能重疊，時間從0開始，開始與結束時間都是整數，
//有n台機器可以同時執行，每台機器同時間只可以執行一個工作，工作可以到每台機器去執行，且工作開始做就需要做完，
//機器執行中不能跳到另一個工作，可以一結束就馬上接著執行另一個工作，機器更換工作很快，可以不考慮切換所需時間，
//Q:執行完後最少需要幾台機器才能完成所有工作？


#include <iostream>
#include <algorithm>

struct Job
{
    int s;
    int e;
};

bool cmp(Job a, Job b)
{
    if (a.s == b.s) return a.e < b.e;
    return (a.s < b.s);
}

using namespace std;

int main()
{
    int n, inUse = 0;

    cin >> n;
    Job jb[n];
    int machine[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> jb[i].s >> jb[i].e;
    }

    sort(jb, jb + n, cmp);
    machine[0] = jb[0].e;
    inUse = 1;

    for (int i = 1; i < n; ++i)
    {
        bool found = false;

        for (int j = 0; j < inUse; ++j)
        {
            // find an available machine
            if (machine[j] <= jb[i].s)
            {
                machine[j] = jb[j].e;
                found = true;
                break;
            }
        }

        // Found no available machine
        if (!found)
        {
            machine[inUse] = jb[i].e;
            inUse++;
        }
    }

    cout << inUse << "\n";

    return 0;
}
