import java.util.*;
public class prime{
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int num,count=0;
        System.out.println("Enter number");
        num=sc.nextInt();
        for(int i=1; i<=num; i++){
            if(num%i==0){
                count=count+1;
            }
        }
        if(count==2){
            System.out.println(num+" is a prime number.");
        }
        else{
            System.out.println(num+" is not a prime number.");
        }
    }
}
