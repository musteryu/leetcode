/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
  var result = Array(n).fill().map((e, i) => new Array(n).fill('.')),
    results = [],
    colCache = [],
    positiveDiagonalCache = [],
    negativeDiagonalCache = [];
  var result;
  var solve = function(row) {
    var col, r;
    if (row === n) {
      r = Array(n).fill().map((e, i) => result[i].slice());
      results.push(r);
      return;
    }
    for (col = 0; col < n; col++) {
      if (colCache[col]) continue;
      if (positiveDiagonalCache[col + row]) continue;
      if (negativeDiagonalCache[row - col + 5]) continue;
      result[row][col] = 'Q';
      colCache[col] = true;
      positiveDiagonalCache[col + row] = true;
      negativeDiagonalCache[row - col + 5] = true;
      solve(row + 1);
      result[row][col] = '.';
      colCache[col] = false;
      positiveDiagonalCache[col + row] = false;
      negativeDiagonalCache[row - col + 5] = false;
    }
    return;
  }
  solve(0);
  return results.map((r, i) => r.map((row, j) => row.join(''))).length;
};