#include<algorithm>
bool cmp(pair<int, int>& a,pair<int, int>& b )
{
    double r1=(double)a.second/(double)a.first;
    double r2=(double)b.second/(double)b.first;
    return r1>r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),cmp);
    
    double ans=0.0;
    int cur_weight=0;
    
    for(int i=0;i<n;i++)
    {
        if(cur_weight+items[i].first<=w)
        {
            ans+=items[i].second;
            cur_weight+=items[i].first;
        }
        else
        {
            int rem=w-cur_weight;
            ans+=(((double)items[i].second/(double)items[i].first)*rem);
            break;
        }
    }
    return ans;
}