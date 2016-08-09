/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
  var _myPow = function(x, n) {
    var t;
    if (n === 1) return x;
    if (n === 0) return 1;
    if (n % 2 === 0) {
      t = _myPow(x, n/2);
      return t * t;
    }
    t = _myPow(x, (n-1) / 2);
    return t * t * x;
  }
  if (n < 0) return 1 / _myPow(x, -n);
  else return _myPow(x, n);
  
};
var x = 0.00001;
var n = 2147483647;
console.log(myPow(x, n));
console.log(Math.pow(x, n));