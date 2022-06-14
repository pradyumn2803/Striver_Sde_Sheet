#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    if(n==0) return 0;
    
    long leftmax=0,rightmax=0,right=n-1,left=0,res=0;
    
    while(left<=right)
    {
        if(arr[left]<=arr[right])
        {
            if(leftmax<arr[left]) leftmax=arr[left];
            else res+=leftmax-arr[left];
            left++;
        }
        else
        {
            if(rightmax<arr[right]) rightmax=arr[right];
            else res+=rightmax-arr[right];
            right--;
        }
    }
    return res;
}