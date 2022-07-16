#include <bits/stdc++.h>
using namespace std;

bool StrStr(string s1, string s2)
{
    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size())
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                return false;
            }
            i++;
        }
    }
    return (j == s2.size());
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << StrStr(s1, s2);
    return 0;
}