#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,x;
	cin>>n>>k>>x;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	priority_queue<pair<int,int> > maxh;
        for(int i=0;i<n;i++)
        {
            maxh.push(make_pair(abs(a[i]-x),a[i]));
            if(maxh.size()>k)
            {
                maxh.pop();
            }
        }
    
        while(maxh.size()>0)
        {
            cout<<maxh.top().second<<" ";
            maxh.pop();
        }
	
	
}
