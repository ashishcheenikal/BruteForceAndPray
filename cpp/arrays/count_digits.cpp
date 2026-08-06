#include <iostream>
using namespace std;

int countDigits(int num)
{
    int digits = 0;
    if (num == 0)
        return 1;

    while (num)
    {
        digits++;
        num /= 10;
    }

    return digits;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int num;
        cin >> num;
        cout << countDigits(num) << '\n';
    }
}