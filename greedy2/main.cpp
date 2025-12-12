//工作排程2-最多有幾台機器一起運作
//有n個工作可以同時執行，給定每個工作的開始時間與結束時間，工作時間可能重疊，時間從0開始，開始與結束時間都是整數，
//有n台機器可以同時執行，每台機器同時間只可以執行一個工作，工作可以到每台機器去執行，且工作開始做就需要做完，
//機器執行中不能跳到另一個工作，可以一結束就馬上接著執行另一個工作，機器更換工作很快，可以不考慮切換所需時間，
//Q:執行完後最少需要幾台機器才能完成所有工作？

//貪婪準則是先將n個工作以開始時間最早的工作排在前面，若開始時間相同就以最早結束的工作排在前面進行排序，將排序好的工作，由最前面依序取出每個工作，優先分配到目前已經執行完畢或沒有工作可以執行的機器，若全部機器都有工作正在執行就需要啟用新的機器。需使用陣列m，紀錄每個機器執行目前工作完成後的時間，才能判斷機器是否有空可以執行下一個工作，還是要啟動新的機器。

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
