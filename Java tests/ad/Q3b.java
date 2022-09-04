import java.util.*;

// selection sort
public class Q3b {
    static void swap(int arr[], int min, int i) {
        int tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int arr[] = { 7, 8, 12, 56, 5 };
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            if (min != i) {
                swap(arr, min, i);
            }
        }

        System.out.println(Arrays.toString(arr));

        sc.close();
    }
}
