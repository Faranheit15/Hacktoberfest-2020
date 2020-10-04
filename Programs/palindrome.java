import java.util.*;
public class palindrome{
    public static void main(String[]args){
        int num,digit,Reverse=0;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter number");
        num=sc.nextInt();
        int temp=num;
        for(;num!=0;){
            digit=num%10;
            Reverse=Reverse*10+digit;
            num=num/10;
        }
        if(Reverse==temp){
            System.out.println(temp+" is a palindrome number");
        }
        else{
            System.out.println(temp+" is not a palindrome number");
        }
    }
}
