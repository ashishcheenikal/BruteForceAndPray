#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void maxNumber(vector<int> &arr, int index, int &max)
{
    if (index == arr.size())
    {
        return;
    }
    if (arr[index] > max)
    {
        max = arr[index];
    }
    maxNumber(arr, index + 1, max);
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
        int max = arr[0];
        maxNumber(arr, 0, max);
        cout << max;
    }

    return 0;
}