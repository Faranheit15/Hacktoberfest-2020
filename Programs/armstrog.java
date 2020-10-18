import java.util.*;
class A
{
public static viod main(String ag[])
Scanner sc=new Scanner(System.in);
int n=sc.nextInt();
int sum,d,num;
sum=0;
num=n;
while(num!=0)
{
d=num%10;
sum=sum+d*d*d;
num=num/10;
}
if(sum==n)
{
System.out.println("Number is Armstrong");
}
else
{
System.out.println("Number is not Armstrong");
}
}


