// https://leetcode.com/problems/move-zeroes/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();

    int j = 0;
    int i = 0;
    while (i < n)
    {
        if (nums[i] != 0)
        {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            j++;
        }
        i++;
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
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        moveZeroes(nums);

        for (const auto &x : nums)
        {
            cout << x << " ";
        }
    }

    return 0;
}