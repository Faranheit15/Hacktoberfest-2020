#include<stdio.h>
void main()
{
 float j,k;
 float number;
 n=0.0001;
 printf("ENTER A N0. : ");
 scanf("%f",&number);

 for(j=0;j<number;j=j+k)
 {
  if((j*j)>number)
  {
   j=j-k;        
   break;      
  }              
 }
 printf("%.2f",j);
 getch();
 return 1;
}
