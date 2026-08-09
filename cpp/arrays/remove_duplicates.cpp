#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (k == 0 || nums[k] != nums[i - 1])
        {
            nums[k] = nums[i];
            k++;
        }
    }

    for (const auto &x : nums)
    {
        cout << x << " ";
    }

    cout << '\n';

    return k;
}

int main()
{
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
        cout << removeDuplicates(nums) << '\n';
    }
}