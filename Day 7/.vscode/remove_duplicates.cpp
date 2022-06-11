int removeDuplicates(vector<int> &arr, int n) {
    if(n==0) return 0;
	int i=0;
    
    for(int j=1;j<n;j++)
    {
        if(arr[j]!=arr[i])
        {
            swap(arr[j],arr[++i]);
        } 
    }
    return i+1;
}