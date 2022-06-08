#include <bits/stdc++.h> 
// tc=O(nlogn)+O(n)   sc=O(1)
vector<vector<int>> pairSum(vector<int> &arr, int s){
   int n=arr.size();
   vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    int left=0,right=n-1;
    
    while(left<right)
    {
        if(arr[left]+arr[right]<s)
        {
            left++;
        }
        else if(arr[left]+arr[right]>s)
        {
            right--;
        }
        else
        {
            if(arr[left]==arr[right])
            {
                int cnt=0;
                for(int i=0;i<n;i++)
                {
                    if(arr[i]==arr[left])
                    {
                        cnt++;
                    }
                }
                cnt=(cnt*(cnt-1))/2;
                vector<int> v(2,0);
                while(cnt)
                {
                    
                    v[0]=arr[left];
                    v[1]=arr[right];
                    ans.push_back(v);
                    cnt--;
                }
               while(left<right && arr[left]==v[0]) 
               {
                     left++;
                }
               while(left<right && arr[right]==v[1]) 
               {
                     right--;
               }
            }
            else
            {
                int cnt1=0,cnt2=0;
                for(int i=0;i<n;i++)
                {
                    if(arr[i]==arr[left])
                    {
                        cnt1++;
                    }
                    else if(arr[i]==arr[right])
                    {
                        cnt2++;
                    }
                    
                }
                int cnt=cnt1*cnt2;
                vector<int> v(2,0);
                while(cnt)
                {
                    
                    v[0]=arr[left];
                    v[1]=arr[right];
                    ans.push_back(v);
                    cnt--;
                }
                while(left<right && arr[left]==v[0]) 
                {
                     left++;
                 }
                  while(left<right && arr[right]==v[1]) 
                  {
                     right--;
                  }
              }
          }
       }

    return ans;
}