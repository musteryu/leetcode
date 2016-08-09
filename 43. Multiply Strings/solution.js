/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function(num1, num2) {
  var len1, len2,
    n1, n2, flag = 1,
    mul;

  if (num1 === '' || num2 === '') return '';

  if (num1 === '0' || num2 === '0') return '0';

  if (num1[0] === '-') {
    num1 = num1.slice(1);
    flag *= -1;
  }
  if (num2[0] === '-') {
    num2 = num2.slice(1);
    flag *= -1;
  }
  n1 = Array.prototype.map.call(num1, (e, i) => e - '0');
  n2 = Array.prototype.map.call(num2, (e, i) => e - '0');
  len1 = n1.length;
  len2 = n2.length;

  mul = Array(len1 + len2).fill(0);

  for (var i = 0; i < len1; i++) {
    for (var j = 0; j < len2; j++) {
      mul[i + j + 1] += n1[i] * n2[j];
    }
  }

  for (var digit = len1 + len2 - 1; digit >= 0; digit--) {
    if (digit > 0) {
      mul[digit - 1] += Math.floor(mul[digit] / 10);
      mul[digit] %= 10;
    }
  }

  mul = mul[0] === 0 ? mul.slice(1) : mul;
  mul[0] *= flag;
  return mul.join('');

};

var num1 = '';
var num2 = '1';
console.log(multiply(num1, num2));