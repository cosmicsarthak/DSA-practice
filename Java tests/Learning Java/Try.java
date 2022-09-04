import java.util.*;

class Try {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // int row = sc.nextInt(), col = 6;
        // sc.nextLine();
        ArrayDeque<ArrayDeque<Integer>> ad = new ArrayDeque<>();

        while (sc.hasNextInt()) {
            ArrayDeque<Integer> tempAl = new ArrayDeque<>();

            for (var el : sc.nextLine().split("\\s+")) {
                tempAl.offerLast(Integer.parseInt(el));
            }
            ad.offerLast(tempAl);
        }

        for (ArrayDeque<Integer> el : ad) {
            for (int el2 : el) {
                System.out.print(el2 + " ");
            }
            System.out.println();
        }

        int extra1 = ad.peekLast().pollLast();
        int extra2 = ad.peekLast().pollLast();

        System.out.println("extra1: " + extra1 + " extra2: " + extra2 + " and sum is: " + (extra1 + extra2));

        System.out.println();

        for (ArrayDeque<Integer> el : ad) {
            for (int el2 : el) {
                System.out.print(el2 + " ");
            }
            System.out.println();
        }

        System.out.println("Conversaion from ArrayDeque to ArrayList");

        ArrayList<ArrayList<Integer>> al = new ArrayList<>();

        for (ArrayDeque<Integer> el : ad) {
            ArrayList<Integer> al2 = new ArrayList<>(el);
            al.add(al2);
        }

        // Printing The New ARRAYLIST
        for (ArrayList<Integer> el : al) {
            for (int el2 : el) {
                System.out.print(el2 + " ");
            }
            System.out.println();
        }
    }
}