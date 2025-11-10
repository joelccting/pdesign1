#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> a, int from, int to, int key)
{
    if (from > to) return -1;

    int mid = (from + to) / 2;

    if (a[mid] == key) return mid;
    else if (a[mid] < key) binarySearch(a, from, mid - 1, key);
    else binarySearch(a, mid + 1, to, key);

    return -1;
}


int main()
{
    //io speed up
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, asize, q, tmp, t, from, to, mid = 0;
    vector<int> ev;

    cin >> asize >> q;

    n = asize;
    while (n)
    {
        cin >> tmp;
        ev.push_back(tmp);
        n--;
    }

//     for (int i = 0; i < ev.size(); ++i)
//    {
//        cout << ev[i] << "\n";
//    }

    while (q)
    {
        cin >> t; //cout << "got:" << t << "\n";
        //binarySearch(ev, ev.begin(), ev.end(), t);
        from = 0;
        to = asize-1;
        while (from <= to)
        {
            mid = (from + to) / 2; //cout << "mid:" << mid << "\n";
            if (ev[mid] == t) break;
            else if (ev[mid] < t) from = mid + 1;
            else to = mid - 1;
        }

        cout << mid << " ";
        q--;
    }


    return 0;
}
