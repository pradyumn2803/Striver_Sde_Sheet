#include <stack>
int largestRectangle(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;

    int ans = 0, width;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            st.pop();
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            ans = max(ans, width * height);
        }
        st.push(i);
    }
    return ans;
}