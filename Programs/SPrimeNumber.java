import java.util.*;
class primeNumber
{
	public static void main (String args[])
	{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int c=2;
		for(int i=2; i<n; i++)
		{
			if(n%i==0)
			{
				c++;
			}
		}
		if (c==2)
		{
			System.out.prinltn("PRIME NUMBER");
		}
		else
		{
			System.out.println("NOT A PRIME NUMBER");
		}
	}
}
