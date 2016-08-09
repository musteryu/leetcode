/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    var fac = function(start, end) {
        var i = start, r = 1;
        for (; i < end; i++) {
            r *= i;
        }
        return r;
    };
    
    var larger = Math.max(m, n), less = Math.min(m, n);
    return fac(larger, larger+less-1) / fac(1, less);
};

console.log(uniquePaths(6, 7));