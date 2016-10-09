public class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int mid = a == 0 ? Integer.MAX_VALUE : -b / (2 * a);
        int partition;
        for (partition = 1; partition < nums.length; ++partition)
            if (nums[partition] >= mid && nums[partition-1] < mid)
                break;
        for (int i = 0; i < nums.length; ++i)
            nums[i] = transform(nums[i], a, b, c);
        int[] res = new int[nums.length];
        int lend = 0, rend = 0, l = 0, r = 0, top = 0;
        if (a < 0) {
            lend = partition;
            rend = partition - 1;
            l = 0;
            r = nums.length - 1;
        } else if (a > 0) {
            l = partition;
            r = partition - 1;
            lend = nums.length;
            rend = -1;
        } else if (b >= 0) {
            l = 0;
            lend = nums.length;
        } else {
            r = nums.length - 1;
            rend = -1;
        }
        while (l < lend && r > rend) {
            if (nums[l] < nums[r])
                res[top++] = nums[l++];
            else
                res[top++] = nums[r--];
        }
        while (l < lend)
            res[top++] = nums[l++];
        while (r > rend)
            res[top++] = nums[r--];
        return res;
    }

    private int[] reverse(int[] nums) {
        int[] res = new int[nums.length];
        for (int i = 0, j = nums.length-1; i < nums.length; ++i, --j)
            res[i] = nums[j];
        return res;
    }

    private int transform(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
}