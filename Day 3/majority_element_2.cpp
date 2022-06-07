#include<algorithm>
vector<int> majorityElementII(vector<int> &arr)
{
    int num1=-1,num2=-1,cnt1=0,cnt2=0;
    int n=arr.size();
    
    for(int i=0;i<n;i++)
    {
        if(num1==arr[i]) cnt1++;
        else if(num2==arr[i]) cnt2++;
        
        else if(cnt1==0)
        {
            num1=arr[i];
            cnt1=1;
        }
        else if(cnt2==0)
        {
            num2=arr[i];
            cnt2=1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
	vector<int> ans;
    int n1=0,n2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num1) n1++;
        else if(arr[i]==num2) n2++;
    }
    if(n1>floor(n/3)) ans.push_back(num1);
    if(n2>floor(n/3)) ans.push_back(num2);
    
    return ans;
}