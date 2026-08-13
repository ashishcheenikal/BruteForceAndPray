// https://leetcode.com/problems/merge-sorted-array/description/

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0;
    int j = 0;
    int index = 0;
    vector<int> nums1Copy(nums1.size());
    for (int i = 0; i < nums1.size(); i++)
    {
        nums1Copy[i] = nums1[i];
    }
    while (i < m && j < n)
    {
        if (nums1Copy[i] < nums2[j])
        {

            nums1[index] = nums1Copy[i];
            i++;
        }
        else
        {
            nums1[index] = nums2[j];
            j++;
        }
        index++;
    }

    while (i < m)
    {
        nums1[index] = nums1Copy[i];
        index++;
        i++;
    }

    while (j < n)
    {
        nums1[index] = nums2[j];
        index++;
        j++;
    }
}

void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int index = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] < nums2[j])
        {

            nums1[index] = nums2[j];
            j--;
        }
        else
        {
            nums1[index] = nums1[i];
            i--;
        }
        index--;
    }

    while (i >= 0)
    {
        nums1[index] = nums1[i];
        index--;
        i--;
    }

    while (j >= 0)
    {
        nums1[index] = nums2[j];
        index--;
        j--;
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
        int m;
        int n;
        cin >> m;
        cin >> n;
        vector<int> nums1(m + n);
        vector<int> nums2(n);

        for (int i = 0; i < m; i++)
        {
            cin >> nums1[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> nums2[i];
        }

        for (const auto &x : nums1)
        {

            cout << x << " ";
        }
    }

    return 0;
}   