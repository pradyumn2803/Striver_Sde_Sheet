#include<algorithm>
struct meeting
{
	int start,end,pos;	
};
bool comp(meeting m1,meeting m2)
{
	if(m1.end>m2.end) return false;
	if(m1.end<m2.end) return true;
	return m1.pos<m2.pos;
}
int maximumActivities(vector<int> &s, vector<int> &f) {
    int n=s.size();
	meeting meet[n];
	for(int i=0;i<n;i++)
	{
		meet[i].start=s[i];
		meet[i].end=f[i];
		meet[i].pos=i+1;
	}
	
	sort(meet,meet+n,comp);
	
	int cnt=1;
	int finish=meet[0].end;
	
	for(int i=1;i<n;i++)
	{
		if(meet[i].start>=finish)
		{
			cnt++;
			finish=meet[i].end;
		}
	}
	return cnt;
}