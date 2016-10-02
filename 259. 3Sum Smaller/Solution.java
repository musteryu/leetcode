public class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int count = 0;
        for (int i = 0; i < n - 2; ++i) {
            int twoTarget = target - nums[i];
            for (int l = i + 1, r = n - 1; l < r; ) {
                if (nums[l] + nums[r] >= twoTarget) {
                    --r;
                } else {
                    count += r - l;
                    ++l;
                }
            }
        } 
        return count;
    }
}