#include <iostream>
using namespace std;

// Always try to find a relation of pattern with j-loop, which is printing loop.
// it's because the i-loop is used to form the rows.
// Mostly pattern from j-loop, rows from i-loop

void square(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << '\n';
    }
}

void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << '\n';
    }
}

void pattern3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << '\n';
    }
}

void pattern4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1 << " ";
        }
        cout << '\n';
    }
}

void pattern5(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << '\n';
    }
}

void pattern6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n - i - 1)
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << '\n';
    }
}

void pattern7(int n)
{
    // Instead of mod operator, we can use a toggle of variable.
    // int toggle = 1;
    // if(toggle ==1){
    //     toggle = 0;
    // } else {
    //     toggle = 1;
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j % 2 == 0)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << '\n';
    }
}

void pattern8(int n)
{
    int toggle = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (toggle == 1)
            {
                cout << toggle << " ";
                toggle = 0;
            }
            else
            {
                cout << toggle << " ";
                toggle = 1;
            }
        }
        cout << '\n';
    }
}

int main()
{
    cout << "Pattern 1" << '\n';
    square(4);
    cout << '\n';
    cout << "Pattern 2" << '\n';
    pattern2(4);
    cout << '\n';
    cout << "Pattern 3" << '\n';
    pattern3(5);
    cout << '\n';
    cout << "Pattern 4" << '\n';
    pattern4(5);
    cout << '\n';
    cout << "Pattern 5" << '\n';
    pattern5(5);
    cout << '\n';
    cout << "Pattern 6" << '\n';
    pattern6(5);
    cout << '\n';
    cout << "Pattern 7" << '\n';
    pattern7(6);
    cout << '\n';
    cout << "Pattern 8" << '\n';
    pattern8(6);
    cout << '\n';
}