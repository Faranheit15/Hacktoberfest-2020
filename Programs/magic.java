import java.util.*;
public class magic{
    public static void main(String[]args){
        int num,digit,sum=0;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter number");
        num=sc.nextInt();
        int temp=num;
        while(num>9){
            while(num>0){
                digit=num%10;
                sum=sum+digit;
                num=num/10;
            }
            num=sum;
            sum=0;
        }
        if(num==1){
            System.out.println(temp+" is a magic number.");
        }
        else{
            System.out.println(temp+" is not a magic number.");
        }
    }
}
