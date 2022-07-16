int atoi(string str) {
    // Write your code here.
    int n = str.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x=str[i]-'0';
        if(x>=0 && x<=9) ans=ans*10+x;
    }
    return (str[0]=='-')?-1*ans:ans;
}