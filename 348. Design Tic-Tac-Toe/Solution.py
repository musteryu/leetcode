class TicTacToe(object):

    def __init__(self, n):
        """
        Initialize your data structure here.
        :type n: int
        """
        self.row = [None, [0] * n, [0] * n]
        self.col = [None, [0] * n, [0] * n]
        self.diagonal = [None, [0] * 2, [0] * 2]
        self.n = n

    def move(self, row, col, player):
        """
        Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins.
        :type row: int
        :type col: int
        :type player: int
        :rtype: int
        """
        self.row[player][row] += 1
        if self.row[player][row] == self.n:
            return player
        
        self.col[player][col] += 1
        if self.col[player][col] == self.n:
            return player

        if row == col:
            self.diagonal[player][0] += 1
        if self.diagonal[player][0] == self.n:
            return player

        if row == self.n - 1 - col:
            self.diagonal[player][1] += 1
        if self.diagonal[player][1] == self.n:
            return player
            
        return 0


# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)