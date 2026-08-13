#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int factorial(int num)
{
    if (num <= 1)
    {
        return 1;
    }

    return num * factorial(num - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int num;
        cin >> num;
        cout << factorial(num);
    }

    return 0;
}