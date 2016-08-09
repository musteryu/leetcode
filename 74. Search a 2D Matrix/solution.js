/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    var binarySearch = function(array, target) {
        var search = function(low, high, target) {
            if (low > high) return false
            var mid = Math.floor((low + high) / 2);
            if (array[mid] === target) return true;
            if (array[mid] > target) return search(low, mid - 1, target);
            if (array[mid] < target) return search(mid+1, high, target);
        };
        return search(0, array.length-1, target);
    }
    var row = matrix.length, col = matrix[0].length, i;
    if (target < matrix[0][0] || target > matrix[row-1][col-1])
        return false;
    for (i = 0; i < row; i++) {
        if (target <= matrix[i][col-1]) 
            return binarySearch(matrix[i], target);
    }
    return false;
};

var matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
];
var target = 16;
console.log(searchMatrix(matrix, target));
