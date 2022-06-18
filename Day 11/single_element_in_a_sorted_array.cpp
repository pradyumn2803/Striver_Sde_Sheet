int uniqueElement(vector<int> arr, int n)
{
	int l=0,h=n-2;
    
    while(l<=h)
    {
        int mid=(l+h)>>1;
        
        if(arr[mid]==arr[mid^1])
            l=mid+1;
        else
            h=mid-1;
    }
    return arr[l];
}
