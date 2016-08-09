/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
  var result = new Array(n).fill().map((e, i) => new Array(n));
  var level = Math.floor((n + 1) / 2),
    i, j, num = 1;
  for (i = 0; i < level; i++) {
    for (j = i; j < n - i - 1; j++) {
      result[i][j] = num++;
    }
    for (j = i; j < n - i - 1; j++) {
      result[j][n - i - 1] = num++;
    }
    for (j = n - i - 1; j > i; j--) {
      result[n - i - 1][j] = num++;
    }
    for (j = n - i - 1; j > i; j--) {
      result[j][i] = num++;
    }
  }
  if (level * 2 === n + 1) {
    result[level - 1][level - 1] = num;
  }
  return result;
};
console.log(generateMatrix(10));