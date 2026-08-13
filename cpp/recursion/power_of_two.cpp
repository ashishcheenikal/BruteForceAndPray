// https://leetcode.com/problems/power-of-two/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool isPowerOfTwo(int n)
{

    cout << n << '\n';

    if (n == 2 || n == 1)
    {
        return true;
    }

    return (n % 2 != 0) ? false : isPowerOfTwo(n / 2);
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
        cout << (isPowerOfTwo(n) ? "true" : "false");
    }

    return 0;
}
