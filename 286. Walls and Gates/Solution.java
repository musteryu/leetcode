public class Solution {
    private final static int INF = Integer.MAX_VALUE - 1;
    private int dfs(int[][] rooms, int rows, int cols, int currRow, int currCol, boolean[][] visited) {
        if (visited[currRow][currCol]) return rooms[currRow][currCol];
        visited[currRow][currCol] = true;
        int distance = INF;
        for (int r = Math.max(currRow-1, 0); r < Math.min(currRow + 2, rows); ++r) {
            for (int c = Math.max(currCol-1, 0); c < Math.min(currCol + 2, cols); ++c) {
                if (r != currRow || c != currCol)
                    distance = Math.min(distance, dfs(rooms, rows, cols, r, c, visited));
            }
        }
        return rooms[currRow][currCol] = distance;
    }
    public void wallsAndGates(int[][] rooms) {
        int rows = rooms.length;
        if (rows == 0) return;
        int cols = rooms[0].length;
        if (cols == 0) return;
        boolean[][] visited = new boolean[rows][cols];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dfs(rooms, rows, cols, i, j, visited);
            }
        }
    }
}