#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    int maxProfit = 0;
    int smallest = prices[0];
    for (int i = 0; i < n; i++)
    {
        int profit = prices[i] - smallest;

        if (profit > maxProfit)
        {
            maxProfit = profit;
        }

        if (prices[i] < smallest)
        {
            smallest = prices[i];
        }
    }

    return maxProfit;
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
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << maxProfit(arr) << '\n';
    }

    return 0;
}