/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
  if (matrix.length === 0) return [];
  var rowNum = matrix.length,
    colNum = matrix[0].length;
  var level, levelMax = Math.min(Math.floor((rowNum - 1) / 2), Math.floor((colNum - 1) / 2)),
    result = [],
    i;
  for (level = 0; level <= levelMax; level++) {
    for (i = level; i < colNum - level; i++) {
      result.push(matrix[level][i]);
    }
    if (rowNum - 1 - level === level) break;
    for (i = level + 1; i < rowNum - level; i++) {
      result.push(matrix[i][colNum - level - 1]);
    }
    if (colNum - 1 - level === level) break;
    for (i = colNum - level - 2; i >= level; i--) {
      result.push(matrix[rowNum - level - 1][i]);
    }
    for (i = rowNum - level - 2; i > level; i--) {
      result.push(matrix[i][level]);
    }
  }
  return result;
};
var matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9],
  [10, 11, 12]
];
console.log(spiralOrder(matrix));