public class Solution {
    public int minCostII(int[][] costs) {
        int n = costs.length;
        if (n == 0) return 0;
        int k = costs[0].length;
        if (k == 0) return 0;
        for (int house = 1; house < n; ++house) {
            int indexOfLastMin = indexOfMinExcept(costs[house-1], -1);
            for (int color = 0; color < k; ++color) {
                if (color != indexOfLastMin)
                    costs[house][color] += costs[house-1][indexOfLastMin];
                else
                    costs[house][color] += costs[house-1][indexOfMinExcept(costs[house-1], indexOfLastMin)];
            }
        }
        return costs[n-1][indexOfMinExcept(costs[n-1], -1)];
    }

    private int indexOfMinExcept(int[] nums, int except) {
        int min = Integer.MAX_VALUE;
        int index = -1;
        for (int i = 0; i < nums.length; ++i) {
            if (i == except) continue;
            if (nums[i] < min) {
                index = i;
                min = nums[i];
            }
        }
        return index;
    }
}