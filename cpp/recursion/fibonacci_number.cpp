// https://leetcode.com/problems/fibonacci-number/
#include <iostream>
#include <vector>

using namespace std;

#define ll = long long;

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << fib(n);
    }
}