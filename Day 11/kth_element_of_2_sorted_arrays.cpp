int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    if(m>n) return ninjaAndLadoos(row2,row1,n,m,k);
    
    int low=(k>n)?k-n:0;
    int high=(k<m)?k:m;
    
    while(low<=high)
    {
        int cut1=(low+high) >> 1;
        int cut2=k-cut1;
        
        int left1=(cut1==0)?-1e9:row1[cut1-1];
        int left2=(cut2==0)?-1e9:row2[cut2-1];
        
        int right1=(cut1==m)?1e9:row1[cut1];
        int right2=(cut2==n)?1e9:row2[cut2];
        
        if(left1<=right2 && left2<=right1)
        {
            return max(left1,left2);
        }
        
        if(left1>right2) high=cut1-1;
        else low=cut1+1;
    }
    return 0;
}