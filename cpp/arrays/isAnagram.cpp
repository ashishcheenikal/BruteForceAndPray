// https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
    {
        return false;
    }

    int freq[26] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string s, t;
        cin >> s >> t;
        cout << isAnagram(s, t);
    }

    return 0;
}