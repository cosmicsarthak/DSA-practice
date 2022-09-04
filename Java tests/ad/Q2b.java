import java.util.*;

public class Q2b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> al = new ArrayList<>();
        while (sc.hasNext()) {
            al.add(sc.nextInt());
        }

        int arr[] = new int[al.size()];
        ArrayList<Integer> tmp = new ArrayList<>();
        for (int el : al) {
            tmp.add(el);
        }
        Collections.reverse(tmp);
        System.out.println("___" + tmp);
        int alxx = -1, tmpxx = -1;
        for (int i = 0; i < al.size(); i++) {
            if (i % 2 != 0) {
                arr[i] = al.get(++alxx);
                System.out.println(Arrays.toString(arr));
            } else if (i % 2 == 0) {
                arr[i] = tmp.get(++tmpxx);
                System.out.println(Arrays.toString(arr));
            }
        }

        System.out.println();
        for (int el : arr) {
            System.out.print(el + " ");
        }

        sc.close();
    }
}