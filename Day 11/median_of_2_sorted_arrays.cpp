double median(vector<int> a, vector<int> b)
{
    if(a.size()>b.size()) return median(b,a);
    int n1=a.size();
    int n2=b.size();
    
    int l=0,h=n1;
    
    while(l<=h)
    {
        int cut1=(l+h)>>1;
        int cut2=((n1+n2+1)/2)-cut1;
        
        int left1= (cut1==0)?-1e9:a[cut1-1];
        int left2= (cut2==0)?-1e9:b[cut2-1];
        
        int right1=(cut1==n1)?1e9:a[cut1];
        int right2=(cut2==n2)?1e9:b[cut2];
        
        if(left1<=right2 && left2<=right1)
        {
            if((n1+n2)%2)
            {
                return max(left1,left2);
            }
            return (max(left1,left2)+min(right1,right2))/2.0;
        }
        else if(left1>right2) h=cut1-1;
        else l=cut1+1;
    }
    return 0.0;
}
