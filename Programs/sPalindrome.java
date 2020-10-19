import java.util.*;
class palindrome
{
	public static void main (String args[])
	{
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		String R="", T=s;
		for(int i=0; i<s.length(); i++)
		{
			char ch=s.charAt(i);
			R=R+ch;
			T=ch+T;
		}
			if(R.equalsIgnoreCase(T))
			{
				System.out.println("PALINDROME");
			}
			else
			{
				System.out.println("NOT A PALINDROME");
			}
		
	}
}
