#include<set>
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    set<int> hsh;
    for(int i=0;i<n;i++)
    {
        hsh.insert(arr[i]);
    }
    int longest_streak=0;
    for(int i=0;i<n;i++)
    {
        if(!hsh.count(arr[i]-1))
        {
            int cur=arr[i];
            int streak=0;
            
            while(hsh.count(cur))
            {
                cur+=1;
                streak+=1;
            }
            longest_streak=max(longest_streak,streak);
        }
    }
    return longest_streak;
}