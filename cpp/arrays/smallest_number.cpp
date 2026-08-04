#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int smallestNumber(const vector<int> &arr)
{
    int smallest = INT_MAX;
    for (auto x : arr)
    {
        if (x < smallest)
        {
            smallest = x;
        }
    }
    return smallest;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);

        // for (int i = 0; i < n; i++)
        // {
        //     cin >> arr[i];
        // }

        for (int &x : arr)
            cin >> x;

        cout << "==" << endl;
        cout << smallestNumber(arr) << endl;
    }
}