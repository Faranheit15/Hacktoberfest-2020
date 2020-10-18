import java.util.Scanner;

// It implements a cipher/encryption.

public class Cipher {

	public static void main(String []args){
		Scanner sc = new Scanner(System.in);
		try{
			System.out.print("Enter the string: ");
			String x = sc.next();
	        String s1="";
	        String s;
	        int n,i;
	        if(x.substring(0,3).equalsIgnoreCase("rot")){
	        	System.out.println("hey");
	        	i=3;
	        	String ind = "";
	        	while(x.charAt(i)!=' ' && x.charAt(i)>='0' && x.charAt(i)<='9'){
	        		ind = ind + x.charAt(i);
	        		i++;
	        	}
	        	System.out.println(ind);
	        	s = x.substring(i);
	        }
	        	
	        for(i=0; i<s.length(); i++){
	            if(s.charAt(i)+n%26>122){
	                s1+=(char)(96+n%26-(122-s.charAt(i)));
	            }
	            else{
	                s1+=s.replace(s.charAt(i), (char)(s.charAt(i)+n%26)).charAt(i);
	            }
	        }
	        System.out.println("Encrypted string: "+s1);
		}
		catch(Exception e){
			System.out.println(e);
		}
		finally{
			sc.close();
		}
     }

}
