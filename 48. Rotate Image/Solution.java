public class Solution {
    public void rotate(int[][] matrix) {
        int m = matrix.length;
        if (m == 0) return;
        for (int i = 0; i < m / 2; ++i) {
            for (int j = 0; j < (m + 1) / 2; ++j) {
                swap4(matrix, i, j);
            }
        }
    }

    private void swap4(int[][] matrix, int i, int j) {
        int m = matrix.length;
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[m-1-j][i];
        matrix[m-1-j][i] = matrix[m-1-i][m-1-j];
        matrix[m-1-i][m-1-j] = matrix[j][m-1-i];
        matrix[j][m-1-i] = tmp;
    }
}
