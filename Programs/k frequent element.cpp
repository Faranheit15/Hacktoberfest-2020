#include<bits/stdc++.h>
#define p pair<int,int>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	map<int,int> m;
	for(int i=0;i<n;i++)
	{
		m[a[i]]++;
	}
	//minheap
	priority_queue<p,vector<p>,greater<p> > minh;
	map<int, int>::iterator it; 
 
	for(it=m.begin();it!=m.end();it++)
	{
		minh.push(make_pair(it->second,it->first));
		if(minh.size()>k)
		{
			minh.pop();
		}
	}
	while(minh.size()>0)
	{
		cout<<minh.top().second<<" ";
		minh.pop();
	}
	return 0;
}
