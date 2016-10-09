public class Solution {
    public int splitArray(int[] nums, int m) {
        int max = 0;
        long sum = 0;
        for (int num: nums) {
            max = Math.max(max, num);
            sum += num;
        } 
        long l = max, r = sum;
        while (l < r) {
            long mid = l + (r - l) / 2;
            if (solvable(nums, m, mid)) r = mid;
            else l = mid + 1;
        }
        return left;
    }

    private boolean solvable(int[] nums, int m, long max) {
        long acc = 0;
        for (int num: nums) {
            if (num > max) return false;
            else if (acc + num <= max) acc += num;
            else {
                --m;
                acc = num;
                if (m <= 0) return false;
            }
        }
        return true;
    }
}