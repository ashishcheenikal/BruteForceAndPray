#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();

    if (n == 1 || n == 0)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        bool isSorted = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = true;
            }
        }
        if (!isSorted)
        {
            break;
        }
    }
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
        bubbleSort(arr);
        for (const auto &x : arr)
        {
            cout << x << " ";
        }
    }

    return 0;
}