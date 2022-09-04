import java.util.*;

public class Q4 {
    static long factorial(long n) {
        if (n == 0) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }

    public static void main(String args[]) {
        System.out.print("Enter the number: ");
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();
        System.out.print("\nFactorial of " + n + " is " + factorial(n));
        sc.close();
    }
}
