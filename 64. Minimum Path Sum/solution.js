/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    var m = grid.length, n = grid[0].length,
        i, j, minSums = Array(m).fill().map((v, i) => new Array(n).fill(0));
    minSums[0][0] = grid[0][0];
    for (i = 1; i < m; i++)
        minSums[i][0] = minSums[i-1][0] + grid[i][0];
    for (j = 1; j < n; j++)
        minSums[0][j] = minSums[0][j-1] + grid[0][j];
    for (i = 1; i < m; i++)
        for (j = 1; j < n; j++)
            minSums[i][j] = grid[i][j] + Math.min(minSums[i][j-1], minSums[i-1][j]);
    return minSums[m-1][n-1];
};

var grid = [
    [1,3,2,4,7,8],
    [5,9,4,3,1,6],
    [1,6,7,4,5,3],
    [9,5,8,6,7,9],
    [1,2,3,9,8,8],
    [2,1,3,4,6,7]
];
console.log(minPathSum(grid));