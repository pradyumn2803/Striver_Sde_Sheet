int cnt_no_less_than_equaltomid(vector<int> &row,int mid)
{
    int l=0,h=row.size()-1;
    
    while(l<=h)
    {
        int md=(l+h)>>1;
        
        if(row[md]<=mid) l=md+1;
        else h=md-1;
    }
    return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    int l=0,h=1e9;
    int n=matrix.size();
    int m=matrix[0].size();
    
    while(l<=h)
    {
        int mid=(l+h)>>1;
        
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            cnt+=cnt_no_less_than_equaltomid(matrix[i],mid);
        }
        
        if(cnt<=(n*m)/2) l=mid+1;
        else h=mid-1;
    }
    return l;
}