import java.util.*;
class fact
{
public static void main(String ag[])
{
Scanner sc=new Scanner(System.in);
int num=sc.nextInt();
int fact=1;
int i=1;
while(i<num)
{
fact=fact*i;
i++;
}
System.out.println("The Factorial of "+num+ "is " +fact);
}
}
