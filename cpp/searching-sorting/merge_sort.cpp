#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void mergeArr(vector<int> &arr, int left, int mid, int right)
{
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int n = leftArr.size();
    int m = rightArr.size();

    int i = 0, j = 0, index = left;
    while (i < n && j < m)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[index] = leftArr[i];
            i++;
        }
        else
        {
            arr[index] = rightArr[j];
            j++;
        }
        index++;
    }

    while (i < n)
    {
        arr[index] = leftArr[i];
        i++;
        index++;
    }
    while (j < m)
    {
        arr[index] = rightArr[j];
        j++;
        index++;
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    mergeArr(arr, left, mid, right);
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
        mergeSort(arr, 0, n - 1);
        for (const auto &x : arr)
        {
            cout << x << " ";
        }
    }

    return 0;
}