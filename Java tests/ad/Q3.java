import java.util.*;

public class Q3 {
    public static void task(List<Integer> nm, int i, int k, List<Integer> res) {
        if (i == nm.size()) {
            if (k == res.size())
                System.out.println(res);
            return;
        }
        res.add(nm.get(i));
        task(nm, i + 1, k, res);
        res.remove(res.size() - 1);
        task(nm, i + 1, k, res);
    }

    public static void main(String[] args) {
        List<Integer> nm = new ArrayList<>();
        List<Integer> res = new ArrayList<>();
        nm.add(1);
        nm.add(2);
        nm.add(3);
        nm.add(4);
        task(nm, 0, 3, res);
    }
}
