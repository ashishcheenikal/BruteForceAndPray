#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int sumOfFirstNNumbers(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    return n + sumOfFirstNNumbers(n - 1);
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
        cout << sumOfFirstNNumbers(n);
    }

    return 0;
}