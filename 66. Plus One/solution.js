/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    var i;
    for (i = digits.length - 1; i >= 0; i--) {
        if (i === digits.length - 1) digits[i] += 1;
        if (digits[i] === 10) {
            digits[i] = 0;
            if (i > 0) digits[i-1] += 1;
            else digits.unshift(1);
        }
        else break;
    }
    return digits;
};

var digits = [9, 9, 9, 9, 9, 9];
console.log(plusOne(digits));