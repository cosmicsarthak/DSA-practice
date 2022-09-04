import java.util.*;

public class Q2 {
    static int fibonacci(int n) {
        if (n <= 1) {
            return n;
        } else {
            return (fibonacci(n - 1) + fibonacci(n - 2));
        }
    }

    public static void main(String args[]) {
        System.out.print("Enter the number: ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.print("\nFibonacci sequence for the first " + n + " elements is ");
        int i = 0;
        while (i < n) {
            System.out.print(fibonacci(i) + " ");
            i++;
        }
        sc.close();
    }

}
