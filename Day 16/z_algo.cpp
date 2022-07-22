int zAlgorithm(string s, string p, int n, int m)
{
	string tot=p+"$"+s;
    int len=tot.size();
    int cnt=0;
    int zarr[len];
    zarr[0]=0;
    int left=0,right=0;
    for(int k=1;k<len;k++)
    {
        if(k>right)
        {
            left=right=k;
            
            while(right<len && tot[right]==tot[right-left])
            {
                right++;
            }
            zarr[k]=right-left;
            right--;
        }
        else
        {
            int pos=k-left;
            if(zarr[pos]<right-k+1)
            {
                zarr[k]=zarr[pos];
            }
            else
            {
                left=k;
                while(right<len && tot[right]==tot[right-left])
                {
                    right++;
                }
                zarr[k]=right-left;
                right--;                
            }
        }
        if(zarr[k]==m) cnt++;
    }
    return cnt;
}