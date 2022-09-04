import java.util.*;

public class Q4 {
    public static void main(String[] args) {
        int[] nums = { 1, 2, 3 };
        System.out.println("All subsets are: " + findSubsets(nums));
    }
    public static List<List<Integer>> findSubsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> subsets = new ArrayList<>();
        helper(nums, 0, subsets, result);
        return result;
    }
    private static void helper(int[] nums, int ind, List<Integer> subsets, List<List<Integer>> result) {
        if (ind >= nums.length) {
            result.add(new ArrayList<>(subsets));
            return;
        }
        helper(nums, ind + 1, subsets, result);
        subsets.add(nums[ind]);
        helper(nums, ind + 1, subsets, result);
        subsets.remove(subsets.size() - 1);
    }
}
