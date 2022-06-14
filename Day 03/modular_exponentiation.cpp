int modularExponentiation(int x, int n, int m) {
	long ans=1;
    while(n)
    {
        if(n%2)
        {
            ans=(ans*1LL*x)%m;
            n--;
        }
        else
        {
            x=(x*1LL*x)%m;
            n/=2;
        }
    }
    return ans;
}