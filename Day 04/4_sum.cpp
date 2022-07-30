#include<vector>
#include<algorithm>
string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(),arr.end());
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int t=target-arr[i]-arr[j];
            int front=j+1;
            int back=n-1;
            
            while(front<back)
            {
                int s=arr[front]+arr[back];
                if(s<t) ++front;
                else if(s>t) --back;
                else
                {
                    return "Yes";
                }           
            }
            while(j+1<n && arr[j+1]==arr[j]) j++;
        }
        while(i+1<n && arr[i+1]==arr[i]) i++;
    }

    return "No";
}
