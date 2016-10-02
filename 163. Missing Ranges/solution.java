public class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> ranges = new LinkedList<>();
        for (int left = lower, i = 0; i <= nums.length; ++i) {
            int right = (i < nums.length ? nums[i] - 1 : upper);
            if (right > left) ranges.add(left + "->" + right);
            else if (right == left) ranges.add(left + "");
            left = right + 2;
        }
        return ranges;
    }
}