// https://leetcode.com/problems/single-number/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> freq;

    for (const auto &x : nums)
    {
        freq[x]++;
    }

    for (const auto &x : nums)
    {
        if (freq[x] == 1)
        {
            return x;
        }
    }

    return -1;
}

// Bitwise XOR
int singleNumber1(vector<int> &nums)
{

    int xorNumber = 0;

    for (const auto &x : nums)
    {
        xorNumber ^= x;
    }

    return xorNumber;
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
        cout << singleNumber(nums) << '\n';
    }

    return 0;
}