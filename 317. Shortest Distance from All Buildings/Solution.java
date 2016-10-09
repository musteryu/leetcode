public class Solution {
    int min = Integer.MAX_VALUE;
    int m, n;
    static int[] dir = {0, 1, 0, -1, 0};

    public int shortestDistance(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        int[][] dist = new int[m][n];
        int step = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    bfs(grid, dist, i, j, --step);
            }
        }
        return min == Integer.MAX_VALUE ? -1 : min;
    }

    private void bfs(int[][] grid, int[][] dist, int row, int col, int step) {
        Queue<Pair> queue = new LinkedList<Pair>();
        queue.offer(new Pair(row, col));
        int level = 0, size = queue.size();
        min = Integer.MAX_VALUE;
        while (size != 0) {
            ++level;
            for (int i = 0; i < size; ++i) {
                Pair node = queue.poll();
                for (int d = 0; d < 4; ++d) {
                    Pair newNode = node.add(dir[d], dir[d+1]);
                    if (isValid(newNode) && grid[newNode.a][newNode.b] == step) {
                        queue.offer(newNode);
                        dist[newNode.a][newNode.b] += level;
                        min = Math.min(dist[newNode.a][newNode.b], min);
                        grid[newNode.a][newNode.b]--;
                    }
                }
            }
            size = queue.size();
        }
    }

    private boolean isValid(Pair p) {
        int a = p.a;
        int b = p.b;
        return 0 <= a && a < m && 0 <= b && b < n;
    }

    private class Pair {
        int a;
        int b;
        Pair(int a_, int b_) {
            a = a_;
            b = b_;
        }
        Pair add(int a_, int b_) {
            return new Pair(a + a_, b + b_);
        }
    }
}