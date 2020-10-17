import java.util.*;

class Traffic {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the signal : ");
        String signal = s.nextLine();
        String response = ((signal.equalsIgnoreCase("red") || signal.equalsIgnoreCase("yellow")) ? "Please stop!"
                : "You're allowed to move");
        System.out.println(response);
    }
}
