#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    inline int min_of_three(int a, int b, int c) {
        return std::min(a, std::min(b, c));
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row < 1) return 0;
        int col = matrix[0].size();
        int max_edge = 0;
        bool flag = false;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            dp[i][0] = matrix[i][0] == '1';
            if (!flag && dp[i][0] == 1) flag = true;
        }
        for (int j = 0; j < col; j++) {
            dp[0][j] = matrix[0][j] == '1';
            max_edge = std::max(dp[0][j], max_edge);
            if (!flag && dp[0][j] == 1) flag = true;
        }
        if (flag) max_edge = 1;
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min_of_three(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                    max_edge = std::max(max_edge, dp[i][j]);
                }
            }
        }
        return max_edge * max_edge;
    }
};