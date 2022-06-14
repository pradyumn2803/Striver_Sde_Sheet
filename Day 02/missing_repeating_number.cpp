//Approach 1

#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int,int> p;
	long long int s=(n*1ll*(n+1))/2ll;
    long long int s2=(n*1ll*(n+1)*1ll*(2ll*n+1))/6ll;
    
    long long int a=0;
    long long int b=0;
    
    for(int i=0;i<n;i++)
    {
        a+=arr[i];
        b+=(arr[i]*1ll*arr[i]);
    }
	
    s=s-a; //x-y
    s2=s2-b; //x^2-y^2
    s2=s2/s;
    
    int x=((s+s2)/2ll);
    int y=((s2-s)/2ll);
    
    bool is_missing_x =true;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            is_missing_x=false;
            break;
        }
    }
    
    if(is_missing_x==true)
    {
        p.first=x;
        p.second=y;
    }
    else
    {
        p.first=y;
        p.second=x;
    }
    
    return p;
}


//Approach 2
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
