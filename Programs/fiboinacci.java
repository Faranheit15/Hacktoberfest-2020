import java.util.*;
class A
{
public static void main(String ag[])
{
Scanner sc=new Scanner(System.in);
System.out.println("enter the limit");
int n=sc.nextInt();
int a=0,b=1,c;
System.out.println("Fibonaci series is :  "+a);
System.out.println(b);
for(int i=1;i<=n-2;i++)
{
c=a+b;
System.out.println(c);
a=b;
b=c;
}
}

