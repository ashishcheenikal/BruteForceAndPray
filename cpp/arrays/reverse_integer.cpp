#include <iostream>
#include <climits>
using namespace std;

int reverse(int x)
{
    if (x > INT_MAX || x < INT_MIN)
    {
        return 0;
    }
    long long reverseInt = 0;
    if (x == 0)
    {
        return x;
    }

    while (x)
    {
        reverseInt = reverseInt * 10 + (x % 10);
        x /= 10;
    }

    if (reverseInt > INT_MAX || reverseInt < INT_MIN)
    {
        return 0;
    }

    return reverseInt;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << reverse(x) << '\n';
    }
}