#include<iostream>
using namespaces std;
int fibo(int n);
int main()
{
int n, i=0;
cout<<"enter the no of terms"<<endl;
cin>>n;
cout<<"Fibonacci Series:"<<endl;
for(i=o;i<n;i++)
{
cout<<" "<<fibo(i);
}
cout<<endl;
return 0;
}
int fibo(int n)
{
if((n==1)||(n=0))
{
return(n);
}
else
{
return(fibo(n-1)+fibo(n-2));
}}

