#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
    int num = x;
    if (num == 0)
    {
        return true;
    }
    if (num < 0)
    {
        return false;
    }
    int reverseNumber = 0;
    while (num)
    {
        int lastDigit = num % 10;
        reverseNumber = reverseNumber * 10 + lastDigit;
        num /= 10;
    }
    return x == reverseNumber;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << (isPalindrome(x) ? "true" : "false") << '\n';
    }
}