public class Solution {
    public int countBattleships(char[][] board) {
        int count = 0;
        int rows = board.length, cols = board[0].length;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (ships(board, i, j))
                    ++count;
        return count;
    }

    private boolean ships(char[][] board, int i, int j) {
        if (board[i][j] != 'X') return false;
        if (i > 0 && board[i-1][j] == 'X') return false;
        if (j > 0 && board[i][j-1] == 'X') return false;
        return true;
    }
}