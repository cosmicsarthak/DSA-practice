import java.util.ArrayList;
import java.util.Scanner;

/**
 * 1
 */
public class Try1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> al = new ArrayList<>();
        while (sc.hasNext()) {
            al.add(sc.nextInt());
        }

        ArrayList<Integer> tmp = al;
        int arr[] = new int[al.size() * 2];
        for (int i = 0; i < 2 * al.size(); i++) {
            if (i % 2 == 0) {
                arr[i] = al.get(al.size() - 1 - i);
            } else if (i % 2 != 0) {
                arr[i] = al.get(i);
            }
        }

        for (int el : arr) {
            System.out.print(el + " ");
        }

        sc.close();
    }
}