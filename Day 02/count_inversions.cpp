long long merge(long long *arr,long long *temp,long long low,long long mid,long long high)
{
    long long i,j,k,cnt=0;
    i=k=low;
    j=mid+1;
    
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            cnt+=((mid+1)-i);
        }
    }
    
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    
    while(j<=high)
    {
        temp[k++]=arr[j++];
    }
    
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i];
    }
    return cnt;
}

long long merge_sort(long long *arr,long long *temp,long long low,long long high)
{
	long long cnt=0,mid;
    if(low<high)
    {
        mid=(low+high)/2;
        cnt+=merge_sort(arr,temp,low,mid);
        cnt+=merge_sort(arr,temp,mid+1,high);
        cnt+=merge(arr,temp,low,mid,high);
    }
    return cnt;
}

long long getInversions(long long *arr, int n){
    long long temp[n];
    
    long long cnt=merge_sort(arr,temp,0,n-1);
    
    return cnt;
}