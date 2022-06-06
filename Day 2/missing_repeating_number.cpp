int set_bit(int n)
{
    int ind;
    for(int i=0;i<64;i++)
    {
        if(((n>>i)&1)==1) ind=i;
    }
    return ind;
}
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int a=0;
    for(int i=0;i<n;i++) a^=arr[i];
	for(int i=0;i<n;i++) a^=(i+1);
    
    int miss=0,repeat=0;
    int rs_bit=set_bit(a);
    
    for(int i=0;i<n;i++)
    {
        if(((arr[i]>>rs_bit)&1)==1) miss^=arr[i];
        else repeat^=arr[i];
    }
    
   	for(int i=1;i<=n;i++)
    {
        if(((i>>rs_bit)&1)==1) miss^=i;
        else repeat^=i;
    }

    bool ism_missing=true;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==miss){
            ism_missing=false;break;
        }
    }
   
    if(ism_missing) 
    {
        return make_pair(miss,repeat);
    }
    else
    {
        return make_pair(repeat,miss);
    }
}
