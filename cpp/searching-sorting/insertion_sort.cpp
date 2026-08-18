#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    if (n <= 1)
    {
        return;
    }

    // save the current element to insert into correct position. Consider of a card need to arrange in the order, first we look into the position where we need to insert it. similarly we need to keep the card in the hand(== saving the current item), then we need find the position. How ? look to the immediate left by (prev = i -1). if its greater that current move it to (prev + 1), and check the next by (prev--). While condition mainly check for the whether we reached the check to left end that is 0 || left most card, or stop at the condition where the card is not greater than prev. insert the current in the (prev+1) because we already do a prev-- check in the while. So the correct position will be (prev+1)
    for (int i = 1; i < n; i++)
    {
        int prev = i - 1;
        int current = arr[i];
        while (prev >= 0 && arr[prev] > current)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;
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
        insertionSort(arr);
        for (const auto &x : arr)
        {
            cout << x << " ";
        }
    }

    return 0;
}