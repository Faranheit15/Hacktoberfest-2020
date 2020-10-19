import java.util.*;
class palindromeNumber
{
	public static void main (String args[])
	{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int R=1, T=n;
		for( ;n!=0; )
		{
			int d=n%10;
			R=R*10+d;
			n=n/10;
		}
			if(R==T)
			{
				System.out.println("PALINDROME");
			}
			else
			{
				System.out.println("NOT A PALINDROME");
			}
		
	}
}
