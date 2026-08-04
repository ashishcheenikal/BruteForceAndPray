#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int secondLargest(const vector<int> &arr)
{
    int n = arr.size();
    int largest = INT_MIN;
    int sLargest = INT_MIN;
    if (n <= 1)
        return -1;

    for (const auto &x : arr)
    {
        // 1 1 2 2 3 3
        // 2 2 2 1 2
        if (largest < x)
        {
            sLargest = largest;
            largest = x;
        }
        else if (sLargest < x && x < largest)
        {
            sLargest = x;
        }
    }

    if (largest == sLargest || sLargest == INT_MIN)
        return -1;

    return sLargest;
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

        for (auto &x : arr)
        {
            cin >> x;
        }

        cout << secondLargest(arr) << '\n';
    }
}