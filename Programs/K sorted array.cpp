#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    priority_queue<int,vector<int>,greater<int> > minh;
	    for(int i=0;i<n;i++)
	    {
	        minh.push(a[i]);
	        if(minh.size()>k)
	        {
	            cout<<minh.top()<<" ";
	            minh.pop();
	        }
	    }
	    while(minh.size()>0)
	    {
	        cout<<minh.top()<<" ";
	        minh.pop();
	    }
	    cout<<endl;
	}
	return 0;
}
