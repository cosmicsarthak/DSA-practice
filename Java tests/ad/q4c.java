import java.util.*;

public class q4c {

    static ArrayList<Integer> part(ArrayList<Integer> al, int p1, int p2) {
        int n = al.size();
        int st = 0;
        int en = n - 1;
        for (int i = 0; i <= en;) {
            if (al.get(i) < p1) {
                Collections.swap(al, st, i);
                st++;
                i++;
            } else if (al.get(i) > p2) {
                Collections.swap(al, en, i);
                en--;
            } else {
                i++;
            }
        }
        return al;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> al = new ArrayList<>();
        int p1 = sc.nextInt();
        int p2 = sc.nextInt();
        while (sc.hasNext()) {
            al.add(sc.nextInt());
        }

        al = part(al, p1, p2);

        System.out.println(al);
        sc.close();
    }
}
