int findMinimumCoins(int amount) 
{
    int amt[]={1,2,5,10,20,50,100,500,1000};
	int cnt=0;
	int i=sizeof(amt)/sizeof(amt[0])-1;
	while(i>=0)
	{
		while(amount>=amt[i])
		{
			cnt++;
			amount-=amt[i];
		}
		i--;
	}
	return cnt;
}
