/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    var row = board.length, col = board[0].length;
    var marked = new Array(row).fill().map((e, i) => new Array(col).fill(false));
    var dfs = function(i, j, wordIndex) {
        var r = false;
        if (board[i][j] === word[wordIndex]) {
            marked[i][j] = true;
            if (wordIndex === word.length - 1) return true;
            if (i > 0 && !marked[i-1][j]) 
                r = r || dfs(i-1, j, wordIndex+1);
            if (i < row-1 && !marked[i+1][j]) 
                r = r || dfs(i+1, j, wordIndex+1);
            if (j > 0 && !marked[i][j-1]) 
                r = r || dfs(i, j-1, wordIndex+1);
            if (j < col-1 && !marked[i][j+1]) 
                r = r || dfs(i, j+1, wordIndex+1);
            if (!r) marked[i][j] = false;
            return r;
        } else return false;
    };
    
    var i, j, r;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (!marked[i][j]) r = dfs(i, j, 0);
            if (r) return r;
        }
    }
    return false;
};

var board = [
    "CAA",
    "AAA",
    "BCD"
    ]

var word = 'AAB';
console.log(exist(board, word));