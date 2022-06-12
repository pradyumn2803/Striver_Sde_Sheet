int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);
    
    int platform=1,result=1;
    int i=1,j=0;
    
    while(i<n && j<n)
    {
        if(at[i]<=dt[j])
        {
            platform++;
            i++;
        }
        else if(at[i]>dt[j])
        {
            platform--;
            j++;
        }
        
        result=max(result,platform);
    }
    return result;
}