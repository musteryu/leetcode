/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function(dividend, divisor) {
  var result = 0;
  var step, incre;
  var negative = (dividend < 0) ^ (divisor < 0);

  if (divisor == 0) return 0;

  dividend = Math.abs(dividend);
  divisor = Math.abs(divisor);

  while (dividend > divisor) {
    step = divisor;
    incre = 1;
    while (dividend > step) {
      dividend -= step;
      result += incre;
      step <<= 1;
      incre <<= 1;
    }
  }
  if (negative) {
    return Math.min(2147483647, result);
  } else {
    return Math.max(-2147483648, result);
  }

};