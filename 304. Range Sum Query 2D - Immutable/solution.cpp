class NumMatrix {
private:
    vector<vector<int>> sums;
    inline int getSum(int row, int col) {
        if (row < 0 || col < 0) return 0;
        else return sums[row][col];
    }
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        if (!row) return;
        int col = matrix[0].size();
        if (!col) return;
        sums = vector<vector<int>> (row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            int sum = 0;
            for (int j = 0; j < col; j++) {
                sums[i][j] = sum += matrix[i][j];
            }
        }
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                sums[i][j] += sums[i-1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2, col2) + getSum(row1-1, col1-1) - getSum(row2, col1-1) - getSum(row1-1, col2);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);