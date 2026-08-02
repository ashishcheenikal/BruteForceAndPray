#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int find_ele;
    cin >> find_ele;
    if (find_ele < 0)
        cout << -1 << endl;
    else
    {
        bool found = false;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == find_ele)
            {
                cout << i << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << -1 << endl;
    }
}