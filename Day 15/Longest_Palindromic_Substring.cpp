#include <algorithm>

string longestPalinSubstring(string str)
{
    // Write your code here.
    int n = str.size();
    string ans;
    int maxi = -1e9;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (i == j)
                dp[i][j] = 1;
            else if ((j - i + 1) == 2 && str[i] == str[j])
                dp[i][j] = 1;
            else if (dp[i + 1][j - 1] == 1 && str[i] == str[j])
            {
                dp[i][j] = 1;
            }
            if (dp[i][j] == 1 && maxi <= (j - i + 1))
            {
                maxi = (j - i + 1);
                ans = str.substr(i, maxi);
            }
        }
    }
    return ans;
}