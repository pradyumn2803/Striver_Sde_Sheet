#include<algorithm>

bool allocate(long long mid,int m,vector<int> time)
{
    long long chapter=1,books=0;
    
    for(int i=0;i<time.size();i++)
    {
        if(time[i]>mid) return false;
        
        if(time[i]+books>mid)
        {
            chapter+=1;
            books=time[i];
        }
        else
        {
            books+=time[i];
        }
    }
    
    if(chapter>m) return false;
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{    
//     sort(time.begin(),time.end());
    
    long long low=0;
    
    long long high=0;
    
    for(int i=0;i<m;i++)
    {
        high+=time[i];
    }
    
    while(low<=high)
    {
        long long mid=(low+high) >>1;
        
        if(allocate(mid,n,time))
        {
            high=mid-1;
        }
        else 
        {
            low=mid+1;
        }
    }
    return low;
}