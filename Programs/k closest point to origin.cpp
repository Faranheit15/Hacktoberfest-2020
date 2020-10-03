#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"Enter total number of points and value of k: "<<endl;
	int n,k;
	cin>>n>>k;
	int a[n][2];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	priority_queue< pair<int, pair<int,int> > > maxh;
	
	for(int i=0;i<n;i++)
	{
		
		maxh.push(make_pair(a[i][0]*a[i][0] + a[i][1]*a[i][1],make_pair(a[i][0],a[i][1])) );
		if(maxh.size()>k)
		{
			maxh.pop();
		}
	}
	while(maxh.size()>0)
	{
		pair<int,int> p = maxh.top().second;
		cout<<p.first<<" "<<p.second<<endl;
		maxh.pop();
	}
	return 0;
}
