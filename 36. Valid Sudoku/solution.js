/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
  var rowCache = Array(9),
    colCache = Array(9),
    boxCache = Array(3);
  var row, col, num;

  var resetCache = function(cache, capacity) {
    if (capacity === 1) {
      cache.splice(0);
    } else {
      for (var i = 0; i < capacity; i++) {
        cache[i] = [];
      }
    }
  }

  resetCache(colCache, 9);
  for (row = 0; row < 9; row++) {
    for (col = 0; col < 9; col++) {
      if (col === 0) {
        resetCache(rowCache, 1);
        if (row % 3 === 0) resetCache(boxCache, 3);
      }

      if (board[row][col] !== '.') {
        num = board[row][col].charCodeAt(0) - '0'.charCodeAt(0);
        if (rowCache[num] || colCache[col][num] || boxCache[Math.floor(col / 3)][num])
          return false;
        rowCache[num] = true;
        colCache[col][num] = true;
        boxCache[Math.floor(col / 3)][num] = true;
      }
    }
  }
  return true;
};

var board = [".87654321", "2........", "3........", "4........", "5........", "6........", "7........", "8........", "98......."];
console.log(isValidSudoku(board));