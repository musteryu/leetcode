/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
  var n = matrix.length, i, j;
  for (i = 0; i < Math.floor(n / 2); i++) {
    for (j = 0; j < Math.floor((n+1) / 2); j++) {
      var a, b, c, d;
      a = matrix[i][j];
      b = matrix[j][n-1-i];
      c = matrix[n-1-i][n-1-j];
      d = matrix[n-1-j][i];
      
      matrix[i][j]          = d;
      matrix[j][n-1-i]      = a;
      matrix[n-1-i][n-1-j]  = b;
      matrix[n-1-j][i]      = c;
    }
  }
};

var matrix = [[1]];
rotate(matrix);
console.log(matrix);