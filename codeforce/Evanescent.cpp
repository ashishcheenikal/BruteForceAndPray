#include <iostream>
#include <algorithm>
using namespace std;

int absoluteLength(string &str, int length)
{

    if (length == 2)
    {
        if (str[0] == str[1])
            return 1;
        return 2;
    }

    for (int i = 1; i < length - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            continue;
        }
        else
        {
            str.erase(i, 1);
            break;
        }
    }

    string abtStr = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (i + 1 == str.length())
        {
            abtStr.push_back(str[i]);
        }
        else
        {
            if (str[i] != str[i + 1])
            {
                abtStr.push_back(str[i]);
            }
            else
            {
                continue;
            }
        }
    }

    return abtStr.length();
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int length;
        string str;
        cin >> length >> str;

        cout << absoluteLength(str, length) << '\n';
    }
}