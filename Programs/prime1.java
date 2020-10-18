import java.util.*;
class prime
{
public static void main(String ag[])
{
Scanner sc=new Scanner(System.in);
int n =sc.nextInt();
int count=0;
if(n==1)
{
  System.out.println(The number is Prime Number ");
  }
for(int i=2;i<n/2;i++)
{
if(n%2==0)
{
count++;
}
}
if(count>0)
  System.out.println(+n+" is not Prime Number ");
else
   System.out.println(+n+" is a Prime Number ");
  }
}

