/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    var a = 1, b = 2, tmp;
    if (n === 1) return a;
    if (n === 2) return b;
    while (n > 1) {
        tmp = b;
        b = a + b;
        a = tmp;
        n--;
    }
    return a;
};