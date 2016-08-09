/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */


var solve = function(board) {
    if (board.length === 0) return;
    const row = board.length, col = board[0].length;
    var dfs = function(i, j) {
        if (i < 0 || i >= row || j < 0 || j >= col) return;
        if (board[i][j] === 'X' || board[i][j] === '*') return;
        board[i][j] = '*';
        if (i+1 < row) dfs(i+1, j);
        if (i-1 > 0) dfs(i-1, j);
        if (j+1 < col) dfs(i, j+1);
        if (j-1 > 0) dfs(i, j-1);
    }
    for (var i = 0; i < row; i++) {
        for (var j = 0; j < col; j++) {
            if (i === 0 || i === row - 1 || j === 0 || j === col - 1) {
                if (board[i][j] === 'O') dfs(i, j);
            }
        }
    }

    for (var i = 0; i < row; i++) {
        for (var j = 0; j < col; j++) {
            if (board[i][j] === '*') board[i][j] = 'O';
            else board[i][j] ='X';
        }
    }
};