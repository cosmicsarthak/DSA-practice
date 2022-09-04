import java.util.*;
public class Q5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> list = new ArrayList<>();
        int n = sc.nextInt();
        for (int i = 0; i <= n - 1; i++) {
            list.add(sc.nextInt());
        }
        helper(list, 0, n - 1);
        sc.close();
    }
    public static void helper(List<Integer> list, int i, int j) {
        if (i == list.size()) {
            System.out.println(list);
            return;
        }
        for (int p = i; p <= j; p++) {
            swap(list, i, p);
            helper(list, i + 1, j);
            swap(list, i, p);
        }
    }

    private static void swap(List<Integer> list, int i, int j) {
        int d = list.get(i);
        list.add(i, list.get(j));
        list.remove(i + 1);
        list.add(j, d);
        list.remove(j + 1);
    }
}
