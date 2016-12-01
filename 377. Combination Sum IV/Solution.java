public class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] res = new int[target + 1];
        Arrays.sort(nums);
        res[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int x : nums) {
                if (i - x < 0) break;
                res[i] += res[i-x];
            }
        }
        return res[target];
    }
}