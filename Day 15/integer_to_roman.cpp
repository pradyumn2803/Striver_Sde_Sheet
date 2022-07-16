#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> mp;

    mp[1000] = "M";
    mp[900] = "CM";
    mp[500] = "D";
    mp[400] = "CD";
    mp[100] = "C";
    mp[90] = "XC";
    mp[50] = "L";
    mp[40] = "XL";
    mp[10] = "X";
    mp[9] = "IX";
    mp[5] = "V";
    mp[4] = "IV";
    mp[1] = "I";

    int a;
    cin >> a;
    string ans = "";

    while (a)
    {
        int d = 0;
        for (auto it : mp)
        {
            if (a / it.first == 0)
                break;
            d = it.first;
        }
        for (int i = 0; i < (a / d); i++)
        {
            ans += mp[d];
        }
        a %= d;
    }
    cout << ans << endl;
    return 0;
}