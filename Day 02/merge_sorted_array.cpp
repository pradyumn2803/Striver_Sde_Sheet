// Approach 1

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int i=0;
	if(m==0) return arr2;
	if(n!=0)
	{
		while(i<m)
		{
			if(arr1[i]>arr2[0])
			{
				swap(arr1[i],arr2[0]);
				sort(arr2.begin(),arr2.end());
			}
			i++;
		}
		
	}
	int j=0;
	while(i<m+n)
	{
		arr1[i++]=arr2[j++];
	}
	
	return arr1;
}

//Approach 2 Gap Method
int next_gap(int n)
{
    if(n<=1) return 0;
    return (n/2)+(n%2);
}

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int i=0,j=0;
    for(int gap=next_gap(gap);gap>0;gap=next_gap(gap))
    {
        for(i=0;i+gap<m;i++)
        {
            if(arr1[i]>arr1[i+gap])
            {
                swap(arr1[i],arr1[i+gap]);
            }
        }
        
        for(j=(gap>m)?(gap-m):0; i<m && j<n;i++,j++)
        {
            if(arr1[i]>arr2[j])
            {
                swap(arr1[i],arr2[j]);
            }
        }
        
        if(j<n)
        {
            for(j=0;j+gap<n;j++)
            {
                if(arr2[j]>arr2[j+gap])
                {
                    swap(arr2[j],arr2[j+gap]);
                }
            }
        }
    }
    int k=0;
    for(i=m;i<(m+n);i++)
    {
        arr1[i]=arr2[k++];
    }
    return arr1;
}