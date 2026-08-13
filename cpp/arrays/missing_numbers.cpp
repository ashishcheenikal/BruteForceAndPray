// https://leetcode.com/problems/missing-number/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    vector<int> arr(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        arr[nums[i]] = 1;
    }

    for (int i = 0; i < n; i++)
    {

        if (arr[i] == 0)
        {
            return i;
        }
    }

    return n;
}

// find some relation with the digit when its distinct and continues and in specific range like [0,n]
int missingNumber1(vector<int> &nums)
{
    int n = nums.size();
    int expectedSum = 0;
    int sum = 0;
    // for (int i = 0; i <= n; i++)
    // {
    //     expectedSum += i;
    // }

    // find the sum using formula
    expectedSum = (n * (n + 1)) / 2;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    return expectedSum - sum;
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
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout << missingNumber1(nums);
    }

    return 0;
}