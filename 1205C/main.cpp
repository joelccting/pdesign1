// 1205C

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i) arr.push_back(i + 1);
    //for (int i = 0; i < n; ++i) cout << arr[i] << endl;

    do {

        for (int x : arr) cout << x << " ";
        cout << "\n";
    } while (next_permutation(arr.begin(), arr.end()));

    return 0;
}
