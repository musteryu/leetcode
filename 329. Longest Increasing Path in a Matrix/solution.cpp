class Solution {
private:
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &mem, int i, int j) {
        int rowLimit = matrix.size();
        int colLimit = matrix[0].size();
        if (mem[i][j]) return mem[i][j];
        int depth = 1;
        for (int row = std::max(0, i-1); row <= std::min(rowLimit-1, i+1); ++row)
            if (row != i && matrix[row][j] > matrix[i][j])
                depth = std::max(depth, dfs(matrix, mem, row, j)+1);
        for (int col = std::max(0, j-1); col <= std::min(colLimit-1, j+1); ++col)
            if (col != j && matrix[i][col] > matrix[i][j])
                depth = std::max(depth, dfs(matrix, mem, i, col)+1);
        return mem[i][j] = depth;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rowLimit = matrix.size();
        if (!rowLimit) return 0;
        int colLimit = matrix[0].size(); 
        if (!colLimit) return 0;
        int maxDepth = 1;
        vector<vector<int>> mem (rowLimit, vector<int>(colLimit));
        for (int row = 0; row < rowLimit; ++row) {
            for (int col = 0; col < colLimit; ++col) {
                maxDepth = std::max(maxDepth, dfs(matrix, mem, row, col));
            }
        }
        return maxDepth;
    }
};