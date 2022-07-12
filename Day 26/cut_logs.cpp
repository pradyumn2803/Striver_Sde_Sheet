#include <vector>
int cutLogs(int K, int N)
{
    vector<int> prev(N + 1, 0), cur(N + 1, 0);

    prev[0] = 0;
    prev[1] = 1;

    for (int n = 0; n <= N; n++)
        prev[n] = n;

    for (int k = 2; k <= K; k++)
    {
        cur[0] = 0;
        cur[1] = 1;
        for (int n = 2; n <= N; n++)
        {
            int ans = 1e9;
            int l = 1, h = n;
            while (l <= h)
            {
                int mid = (l + h) >> 1;

                int go_above = cur[n - mid];
                int go_below = prev[mid - 1];

                int temp = 1 + max(prev[mid - 1], cur[n - mid]);

                if (go_above > go_below)
                    l = mid + 1;
                else
                    h = mid - 1;

                ans = min(ans, temp);
            }
            cur[n] = ans;
        }
        prev = cur;
    }
    return prev[N];
}
