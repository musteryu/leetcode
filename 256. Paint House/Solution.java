public class Solution {
    public int minCost(int[][] costs) {
        if (costs == null || costs.length == 0) return 0;
        int n = costs.length;
        for (int i = 1; i < n; ++i) {
            for (int curr = 0; curr < 3; ++curr) {
                if (curr == 0)
                    costs[i][curr] += Math.min(costs[i-1][1], costs[i-1][2]);
                else if (curr == 1)
                    costs[i][curr] += Math.min(costs[i-1][0], costs[i-1][2]);
                else
                    costs[i][curr] += Math.min(costs[i-1][0], costs[i-1][1]);
            }
        }
        return Math.min(costs[n-1][0], Math.min(costs[n-1][1],
                                                costs[n-1][2]));        
    }
}