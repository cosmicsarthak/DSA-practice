import java.util.*;

public class Q3 {
    public static void main(String args[]) {
        System.out.print("Enter the number: ");
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();
        long temp = 1;
        for (long i = 1; i <= n; i++) {
            temp *= i;
        }
        System.out.print("Factorial of " + n + " is " + temp);
        sc.close();
    }
}
