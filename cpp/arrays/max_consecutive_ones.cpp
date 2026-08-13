// https://leetcode.com/problems/max-consecutive-ones/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int maxCount = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;
            if (maxCount < count)
            {
                maxCount = count;
            }
        }
        else
        {
            count = 0;
        }
    }

    return maxCount;
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
        cout << findMaxConsecutiveOnes(nums) << '\n';
    }

    return 0;
}