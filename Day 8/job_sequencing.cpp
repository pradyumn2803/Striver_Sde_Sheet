#include<algorithm>
bool comp(vector<int> &a,vector<int> &b)
{
    return a[1]>b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n=jobs.size();
    int deadline=jobs[0][0];
    for(int i=1;i<n;i++)
    {
        deadline=max(deadline,jobs[i][0]);
    }
    vector<int> slots(deadline+1,-1);
    int profit=0;
    sort(jobs.begin(),jobs.end(),comp);
    for(int i=0;i<n;i++)
    {
        for(int j=jobs[i][0];j>0;j--)
        {
            if(slots[j]==-1) {
                slots[j]=i;
                profit+=jobs[i][1];
                break;
            }
        }
    }
    return profit;
}
