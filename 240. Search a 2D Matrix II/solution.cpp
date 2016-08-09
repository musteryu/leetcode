class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int i = row - 1, j = 0;
        while (i >= 0 && j < col) {
            if (matrix[i][j] < target) {
                j++;
            } else if (matrix[i][j] > target) {
                i--;
            } else return true;
        }
        return false;
    }
};