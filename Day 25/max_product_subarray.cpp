int maximumProduct(vector<int> &arr, int n)
{
    
    int maxi=1,mini=1,ans=-1e9;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0) swap(maxi,mini);
        maxi=max(arr[i],maxi*arr[i]);
        mini=min(arr[i],mini*arr[i]);
        ans=max(maxi,ans);
    }
    return ans;
}
