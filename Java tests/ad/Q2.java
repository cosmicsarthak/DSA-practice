import java.util.*;
public class Q2 {
    public static void main(String[] args) {
        ArrayList<Integer> set = new ArrayList<>();
        set.add(1);
        set.add(2);
        set.add(3);
        set.add(4);
        findPerm(set, 0, set.size() - 1);
    }
    public static void findPerm(ArrayList<Integer> set, int i, int j) {
        if (i == set.size()) {
            int k;
            for (k = 0; k <= set.size() - 1; k++) {
                if (set.get(k) == k + 1)
                    break;
            }
            if (k == set.size()) {
                System.out.println(set);
            }
        }
        for (int p = i; p <= j; p++) {
            swap(set, i, p);
            findPerm(set, i + 1, j);
            swap(set, i, p);
        }
    }

    private static void swap(ArrayList<Integer> set, int i, int j) {
        int d = set.get(i);
        set.add(i, set.get(j));
        set.remove(i + 1);
        set.add(j, d);
        set.remove(j + 1);
    }
}