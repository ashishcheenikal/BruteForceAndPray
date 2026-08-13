#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int sumOfArray(vector<int> &arr, int n)
{

    if (n <= 0)
    {
        return arr[0];
    }

    return arr[n] + sumOfArray(arr, n - 1);
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
        cout << sumOfArray(arr, n - 1);
    }

    return 0;
}