public class Solution {
    public int maxKilledEnemies(char[][] grid) {
        int m = grid.length;
        if (m == 0) return 0;
        int n = grid[0].length;
        int[][] kill = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 'W') {
                    int k = j;
                    int count = 0;
                    while (k < n && grid[i][k] != 'W') {
                        if (grid[i][k++] == 'E') count++;
                    }
                    for (;j < k; ++j) {
                        if (grid[i][j] == '0')
                            kill[i][j] += count;
                    }
                } else {
                    kill[i][j] += 0;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] != 'W') {
                    int k = i;
                    int count = 0;
                    while (k < m && grid[k][j] != 'W') {
                        if (grid[k++][j] == 'E') count++;
                    }
                    for (;i < k; ++i) {
                        if (grid[i][j] == '0') 
                            kill[i][j] += count;
                    }
                } else {
                    kill[i][j] += 0;
                }
            }
        }
        int max = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                max = Math.max(kill[i][j], max);
            }
        }
        return max;
    }
}