import java.util.*;
public class armstrong{
    public static void main(String[]ags){
        int num,digit,sum=0;
        Scanner sc=new Scanner(System.in);
        System.out.println("enter number");
        num=sc.nextInt();
        int temp=num;
        for(;num!=0;){
            digit=num%10;
            sum=sum+(digit*digit*digit);
            num=num/10;
        }
        if(sum==temp){
            System.out.println(temp+" is an armstrong number.");
        }
        else{
            System.out.println(temp+" is not an armstrong number.");
        }
    }
}
