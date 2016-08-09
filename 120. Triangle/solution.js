/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
    var len = triangle.length;
    var last = [0];
    var curr;
    for (var level = 0; level < len; level++) {
        curr = [];
        for (var i = 0; i <= level; i++) {
            curr[i] = Math.min(
                last[i-1] == undefined ? Infinity : last[i-1], 
                last[i] == undefined ? Infinity : last[i]
            ) + triangle[level][i];
        }
        last = curr;
    } 
    return Math.min.apply(this, last);
};

var triangle = [[-10]];
console.log(minimumTotal(triangle));