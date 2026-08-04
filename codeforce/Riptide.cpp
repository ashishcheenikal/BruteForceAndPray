#include <iostream>
#include <algorithm>
using namespace std;

bool isGameEnd(int a, int b, int c)
{
    return (a == b || b == c || a == c);
}

int totalRounds(int a, int b, int c)
{
    int rounds = 0;

    while (!isGameEnd(a, b, c))
    {
        if (a > b && a > c)
            a--;
        else if (b > a && b > c)
            b--;
        else
            c--;

        if (a < b && a < c)
            a++;
        else if (b < a && b < c)
            b++;
        else
            c++;

        rounds++;
    }

    return rounds;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        cout << totalRounds(a, b, c) << '\n';
    }

    return 0;
}