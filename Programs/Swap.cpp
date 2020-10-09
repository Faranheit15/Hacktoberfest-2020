#include<iostream>
using namespace std;

// Swap Function
void Swap(int &a,int &b)
{
   a = a + b;
   b = a - b;
   a = a - b;
}

int main()
{
   int a,b;
   cout<<"\nEnter the First number ";
   cin>>a;
   cout<<"\nEnter the Second number ";
   cin>>b;
   cout<<"\nThe values before swapping are "<<a <<" and "<<b;
   Swap(a,b);
   cout<<"\nThe values after swapping are "<<a <<" and "<<b;
}
