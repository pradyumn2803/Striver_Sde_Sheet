
bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    vector<bool> prev(k+1,0),cur(k+1,0);
    
    prev[0]=cur[0]=1;
  	
    prev[arr[0]]=1;
    
    for(int ind=1;ind<n;ind++)
    {
        cur[0]=1;
        for(int target=1;target<=k;target++)
        {
            bool take=false;
            if(target>=arr[ind]) 
                take= prev[target-arr[ind]];
            int not_take=prev[target];

            cur[target]=take | not_take;
        }
        prev=cur;
    }    
   	return prev[k];
}