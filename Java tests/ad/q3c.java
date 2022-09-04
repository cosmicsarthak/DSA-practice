import java.util.*;

public class q3c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> al = new ArrayList<>();
        while (sc.hasNext()) {
            al.add(sc.nextInt());
        }
        int n = al.size();
        Collections.sort(al);
        System.out.println(al);
        int count = 1;
        for (int i = 1; i < n; i++) {

            if (al.get(i) != al.get(i - 1)) {
                if (count % 2 != 0) {
                    System.out.println(al.get(i - 1));
                }
                count = 1;
                // System.out.println(al.get(i - 1) + "___" + al.get(i) + "..." + count + "\n");
            } else {
                ++count;
                // System.out.println("\n" + al.get(i - 1) + "___" + al.get(i) + "..." + count);
                if (i == n - 1) {
                    if (count % 2 != 0) {
                        System.out.println(al.get(i));
                    }
                }
            }
        }

        sc.close();
    }
}
