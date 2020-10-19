import java.util.*;
class Reverse
{
	public static void main (String args[])
	{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int R=1;
		for( ;n!=0; )
		{
			int d=n%10;
			R=R*10+d;
			n=n/10;
		}
			
		System.out.println("REVERSE OF THE NUMBER=" + R);
	}
}
