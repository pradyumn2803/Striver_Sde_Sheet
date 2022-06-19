int check(vector<int> a , int n ,  int c,int val)
{
    int cnt=1,coordinate=a[0];
    
    for(int i=1;i<n;i++)
    {
        if(a[i]-coordinate>=val)
        {
            coordinate=a[i];
            cnt++;
        }
        if(cnt==c) return 1;
    }
    return 0;
}

int chessTournament(vector<int> a , int n ,  int c){
	sort(a.begin(),a.end());
    int low=1,high=a[n-1]-a[0];
    while(low<=high)
    {
        int mid=(low+high) >> 1;
        
        if(check(a,n,c,mid))
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    
    return high;
}