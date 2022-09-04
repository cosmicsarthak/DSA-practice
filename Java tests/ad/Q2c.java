import java.util.*;

public class Q2c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> al = new ArrayList<>();
        int x = sc.nextInt();
        while (x != 0) {
            al.add(x % 8);
            x /= 8;
        }

        Collections.reverse(al);
        System.out.println(al);
        sc.close();
    }
}