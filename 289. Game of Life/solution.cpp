class Solution {
private:
    int neighbors(vector<vector<int>> &board, int i, int j) {
        int n = 0;
        int row = board.size(), col = board[0].size();
        for (int r = max(0, i-1); r < min(i+2, row); r++)
            for (int c = max(0, j-1); c < min(j+2, col); c++)
                n += board[r][c] & 1;
        n -= board[i][j] & 1;
        return n;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        if (!row) return;
        int col = board[0].size();
        if (!col) return;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int n = neighbors(board, i, j);
                if (n >= 2 && n <= 3 && board[i][j] & 1 || n == 3 && !(board[i][j] & 1))
                    board[i][j] |= 2;
            }
        }        
        for (auto &v: board)
            for (auto &e: v)
                e >>= 1;
    }
};