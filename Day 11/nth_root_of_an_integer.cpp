double multiply(double number,int n)
{
    double ans=1.0;
    for(int i=0;i<n;i++)
    {
        ans=ans*(number);
    }
    return ans;
}
double findNthRootOfM(int n, long long m) {
	double low=1.0;
    double high=m;
    double eps=1e-7;
    
    while((high-low)>eps)
    {
        double mid=(high+low)/2.0;
        if(multiply(mid,n)<m)
        {
            low=mid;
        }
        else high=mid;
    }
    
    return low;
}
