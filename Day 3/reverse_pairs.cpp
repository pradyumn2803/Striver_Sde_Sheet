int merge(int low,int mid,int high,vector<int> &arr)
{
    int j=mid+1,cnt=0;
    for(int i=low;i<=mid;i++)
    {
        while(j<=high && arr[i]> 2LL*arr[j])
        	j++;
        cnt+=(j-(mid+1));
    }
    
    vector<int> temp;
    int a=low;
    int b=mid+1;
    
    while(a<=mid && b<=high)
    {
        if(arr[a]<=arr[b])
            temp.push_back(arr[a++]);
        else
            temp.push_back(arr[b++]);
    }
    
    while(a<=mid)
        temp.push_back(arr[a++]);
    while(b<=high)
        temp.push_back(arr[b++]);
    
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
    return cnt;
}

int ms(int low,int high,vector<int> &arr)
{
    if(low>=high) return 0;
    int mid=(low+high)/2;
    int cnt=ms(low,mid,arr);
    cnt+=ms(mid+1,high,arr);
    cnt+=merge(low,mid,high,arr);
    return cnt;
}

int reversePairs(vector<int> &arr, int n){
	return ms(0,n-1,arr);	
}