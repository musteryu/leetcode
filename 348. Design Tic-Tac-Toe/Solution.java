public class TicTacToe {

    /** Initialize your data structure here. */
    private int[][] rowCnt, colCnt, diagCnt;
    private int n;
    public TicTacToe(int n) {
        this.n = n;
        rowCnt = new int[][] { new int[n], new int[n] };
        colCnt = new int[][] { new int[n], new int[n] };
        diagCnt = new int[][] { new int[] {0, 0}, new int[] {0, 0} };
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    public int move(int row, int col, int player) {
        if (++rowCnt[player-1][row] == n 
            || ++colCnt[player-1][col] == n 
            || row == col && ++diagCnt[player-1][0] == n
            || row + col == n - 1 && ++diagCnt[player-1][1] == n)
            return player;
        return 0;
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */