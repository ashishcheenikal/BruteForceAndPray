#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int NumOfItems(vector<int> &arr, int index)
{
    if (index == arr.size())
    {
        return 0;
    }

    return 1 + NumOfItems(arr, index + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << NumOfItems(arr, 0);
    }

    return 0;
}