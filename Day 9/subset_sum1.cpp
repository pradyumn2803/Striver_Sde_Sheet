void f(int i,int sum,int n,vector<int> &num,vector<int> &ds)
{
    if(i==n)
    {
        ds.push_back(sum);
        return ;
    }
    
    f(i+1,sum+num[i],n,num,ds);
    f(i+1,sum,n,num,ds);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ds;
    int n=num.size();
    f(0,0,n,num,ds);
    
    sort(ds.begin(),ds.end());
    return ds;
}