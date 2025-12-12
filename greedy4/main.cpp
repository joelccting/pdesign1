//工作排程-4 有截止期限的最大利潤
//有n個工作從開始所有工作就進入到機器，給予n個工作的截止時間與獲得的利潤，
//只有一台機器可以執行，每個工作都需花費一個單位時間執行，
//Q:請計算如何安排工作在截止時間前執行，可以獲得最大利潤？

//解題想法
//貪婪準則是優先考慮利潤最高的工作，將利潤高的工作優先新增到機器，
//若不違反已經選取的工作，則加入到預計執行工作的集合，否則丟棄此工作，
//所謂違反是指新選取的工作無法在截止時間內完成，或造成已經選取的工作無法完成。
//最後取出預計執行工作的集合，計算所獲得的最大利潤。

#include <iostream>
#include <algorithm>

using namespace std;

struct Task
{
    int dline;
    int profit;
};

bool cmp(Task a, Task b)
{
    if (a.profit == b.profit) return a.dline < b.dline;
    return (a.profit > b.profit);
}

bool cmp2(Task a, Task b)
{
    return a.dline < b.dline;
}

int main()
{
    int n, sidx;
    cin >> n;
    Task t[n], selected[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i].dline >> t[i].profit;
    }

    sort(t, t + n, cmp);

    for (int i = 0; i < n; ++i)
    {
        cout << "Sorted task " << i << " deadline: " << t[i].dline << "; profit: " << t[i].profit << "\n";
    }

    selected[0] = t[0];
    sidx = 1;

    for (int i = 1; i < n; ++i)
    {
        bool found = false;
        int j;
        for (j = 0; j < sidx; ++j)
        {
            if (selected[j].dline >= t[i].dline)
            {
                found = true;
                break;
            }
        }

        while (found && (j < (sidx - 1)) && (selected[j + 1].dline == selected[j].dline))
        {
            ++j;
        }

        // no conflict
        if (!found)
        {
            selected[sidx] = t[i];
            sidx++;

            cout << "Add task " << i << " deadline: " << t[i].dline << "; profit: " << t[i].profit << "\n";
            sort(selected, selected + sidx, cmp2);
        }
        else if ((j + 1) < t[i].dline)
        {
            selected[sidx] = t[i];
            sidx++;
            cout << "Add task " << i << " deadline: " << t[i].dline << "; profit: " << t[i].profit << "\n";
            sort(selected, selected +sidx, cmp2);
        }

    }

    int sum = 0;
    for (int i = 0; i < sidx; ++i)
    {
        sum += selected[i].profit;
    }

    cout << sum << "\n";

    return 0;
}
