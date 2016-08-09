import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by musteryu on 16/4/30.
 */
public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> subsets = new ArrayList<>();
        subsets.add(new ArrayList<>());
        int lastNumIndex = 0, oldLen = 0;

        for (int i = 0; i < nums.length; i++) {
            oldLen = subsets.size();
            if (i == 0 || nums[i] != nums[i-1]) {
                for (int j = 0; j < oldLen; j++) {
                    ArrayList<Integer> s = new ArrayList<Integer>(subsets.get(j));
                    s.add(nums[i]);
                    subsets.add(s);
                }
                lastNumIndex = oldLen;
            } else {
                oldLen = subsets.size();
                for (int j = lastNumIndex; j < oldLen; j++) {
                    ArrayList<Integer> s = new ArrayList<Integer>(subsets.get(j));
                    s.add(nums[i]);
                    subsets.add(s);
                }
                lastNumIndex = oldLen;
            }
        }
        return subsets;
    }

    public static void main(String[] args) {
        int[] nums = {2, 2, 2, 2, 2};
        List<List<Integer>> subsets = new Solution().subsetsWithDup(nums);
        for (List<Integer> l: subsets) {
            System.out.print("[ ");
            for (Integer i: l) {
                System.out.print(i + " ");
            }
            System.out.println("]");
        }
    }
}
