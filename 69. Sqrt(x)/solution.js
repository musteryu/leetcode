/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    var v = x;
    while (v * v > x) {
        v = Math.floor((v + Math.floor(x / v)) / 2);
    }
    return v;
};