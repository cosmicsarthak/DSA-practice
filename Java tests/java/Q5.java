import java.util.*;

public class Q5 {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        // Arithmetic Exception
        try {
            int data = 100 / 0;
        } catch (ArithmeticException e) {
            System.out.println("<== Arithmetic Exception");
        }
        System.out.println("My code WITHOUT Exception\n");

        // Null Pointer Exception
        try {
            String s = null;
            System.out.println(s.length());
        } catch (NullPointerException e) {
            System.out.println("<==Null Pointer Exception detected");
        }
        System.out.println("My code WITHOUT Exception\n");

        // Number Format Exception
        try {
            String s = "abc";
            int i = Integer.parseInt(s);
        } catch (NumberFormatException e) {
            System.out.println("<==Number Format Exception detected");
        }
        System.out.println("My code WITHOUT Exception\n");

        // Array Out Of Bounds Exception
        try {
            int a[] = new int[7];
            a[15] = 50;
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("<==Array Out Of Bounds Exception detected");
        }
        System.out.println("My code WITHOUT Exception");
        sc.close();
    }
}
