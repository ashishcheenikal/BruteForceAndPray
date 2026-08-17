#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void selectionSort(vector<int> &arr)
{

    int n = arr.size();
    if (n <= 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    { // n-1 because last number will be automatically sorted(swapped).
        int min = i;
        for (int j = i + 1; j < n; j++)
        { // i + 1 because the comparison starts from next element
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
        selectionSort(arr);
        for (const auto &x : arr)
        {
            cout << x << " ";
        }
    }

    return 0;
}