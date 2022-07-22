int minCharsforPalindrome(string str) {
    
    int n = str.size();
    int left=0,right=n-1;
    int ans=0;
    while(left<right)
    {
        if(str[left]==str[right])
        {
            left++;
            right--;
        }
        else
        {
            left=0;
            ans=n-right;
            while(str[left]==str[right])
            {
                ans--;
                left++;
            }
            right--;
        }
    }
    return ans;
}
