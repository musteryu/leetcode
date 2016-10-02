public class Solution {
    public int minTotalDistance(int[][] grid) {
        int rowNum = grid.length, colNum = grid[0].length;
        int[] row = new int[rowNum];
        int[] col = new int[colNum];
        for (int r = 0; r < rowNum; ++r) {
            for (int c = 0; c < colNum; ++c) {
                if (grid[r][c] == 1) {
                    ++row[r];
                    ++col[c];
                }
            }
        }
        int total = 0;
        for (int[] dim: new int[][] {row, col}) {
            int l = 0, r = dim.length - 1;
            while (l < r) {
                int k = Math.min(dim[l], dim[r]);
                total += k * (r - l);
                if ((dim[r] -= k) == 0) r--;
                if ((dim[l] -= k) == 0) l++;
            }
        }
        return total;
    }
}