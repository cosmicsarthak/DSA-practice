
// { Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class Try {

    static ArrayList<Integer> subarraySum(int[] ar, int n, int s) {
        ArrayList<Integer> al = new ArrayList<>();
        ArrayList<Integer> res = new ArrayList<>();
        al.add(ar[0]);
        for (int i = 1; i < n; i++) {
            al.add(ar[i] + al.get(i - 1));
        }
        boolean ck = false;
        for (int i = 0; i < n; i++) {
            int diff = s - al.get(i);
            if (diff < 0) {
                System.err.println(diff + "_______________");
                diff *= -1;
                System.err.println(diff + "_now______________");
            }
            System.err.print("__dif..." + diff + "->" + s + " - " + al.get(i));
            int tmp = al.indexOf(diff);
            System.err.print(" __tmp__" + tmp + "\n");
            if (tmp != -1 && diff != al.get(i)) {
                res.add(tmp + 2);
                res.add(i + 1);
                ck = true;
                break;
            } else if (diff == 0) {
                res.add(1);
                res.add(i + 1);
                ck = true;
                break;
            }
        }

        for (var el : al) {
            System.err.print(el + " ");
        }
        System.err.println();

        if (ck) {
            return res;
        } else {
            res.add(-1);
            return res;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int s = sc.nextInt();

        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        ArrayList<Integer> res = subarraySum(a, n, s);
        for (int ii = 0; ii < res.size(); ii++)
            System.out.print(res.get(ii) + " ");
        System.out.println();
        sc.close();
    }

}// } Driver Code Ends
