#include<string.h>
int compareVersions(string a, string b) 
{
    long long i=0,j=0,n1=0,n2=0;
    
    while(i<a.size() || j<b.size())
    {
        n1=n2=0;
        while(i<a.size() && a[i]!='.')
        {
            n1=n1*10+(a[i]-'0');
            i++;
        }
        while(j<b.size() && b[j]!='.')
        {
            n2=n2*10+(b[j]-'0');
            j++;
        }
        if(n1<n2) return -1;
        if(n1>n2) return 1;
        i++;
        j++;
    }
    return 0;
}