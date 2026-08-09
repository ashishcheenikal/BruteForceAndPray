#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char> &s)
{

    int n = s.size();
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }

    for (const auto &x : s)
    {
        cout << x << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        reverseString(arr);
    }
}