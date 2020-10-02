import java.util.*;
class eveoddindexes
{
    public static void main(String arg[])
    {
        Scanner Sc=new Scanner(System.in);
        int arr[]=new int[5];
        System.out.println("Enter 5 numbers");
        for(int i=0;i<5;i++)
        {
            arr[i]=Sc.nextInt();
        }    
        int sum1=0,sum2=0;
        System.out.println("Conents of arrays are as follows");
        for(int i=0;i<5;i++)
        {
            if(i%2==0)
            sum1=sum1+arr[i];
            else
            sum2=sum2+arr[i];
        }
        System.out.println("the sum of even index elements is "+sum1);
        System.out.println("the sum of odd index elements is "+sum2);
    }
}
