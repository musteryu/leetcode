/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    var i, j, k, l, row = matrix.length, col = matrix[0].length;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (matrix[i][j] === 0) {
                matrix[i][j] = '*';
                for (k = 0; k < row; k++)
                    if (matrix[k][j] !== 0) matrix[k][j] = '*';
                for (l = 0; l < col; l++)
                    if (matrix[i][l] !== 0) matrix[i][l] = '*';
            }
        }
    }
    
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (matrix[i][j] === '*')
                matrix[i][j] = 0;
        }
    }
};

var matrix = [
    [0, 1, 2, 3],
    [1, 2, 0, 4],
    [1, 2, 1, 2],
    [0, 2, 1, 2]
];
setZeroes(matrix);
console.log(matrix);