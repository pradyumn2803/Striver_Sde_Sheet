#include<algorithm>
struct activity
{
	int start,end,pos;	
};
bool comp(activity m1,activity m2)
{
	if(m1.end>m2.end) return false;
	if(m1.end<m2.end) return true;
	return m1.pos<m2.pos;
}
int maximumActivities(vector<int> &s, vector<int> &f) {
    int n=s.size();
	activity a[n];
	for(int i=0;i<n;i++)
	{
		a[i].start=s[i];
		a[i].end=f[i];
		a[i].pos=i+1;
	}
	
	sort(a,a+n,comp);
	
	int cnt=1;
	int finish=a[0].end;
	
	for(int i=1;i<n;i++)
	{
		if(a[i].start>=finish)
		{
			cnt++;
			finish=a[i].end;
		}
	}
	return cnt;
}