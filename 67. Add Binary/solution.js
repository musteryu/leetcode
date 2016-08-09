/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    var result, shorter, longer, si, li, flag;
    if (a.length >= b.length) {
        longer = a;
        shorter = b;
    } else {
        longer = b;
        shorter = a;
    }
    result = longer.split('').map((e, i) => e.charCodeAt(0) - '0'.charCodeAt(0));
    for (si = shorter.length - 1, li = longer.length - 1; li >= 0; li--, si--) {
        if (si >= 0)
            result[li] += shorter[si].charCodeAt(0) - '0'.charCodeAt(0);
        if (result[li] > 1) {
            flag = Math.floor(result[li] / 2);
            result[li] = result[li] % 2;
            if (li > 0) result[li-1] += flag;
            else result.unshift(flag);
        }
    }
    return result.join('');
};

var a = '1111111111', 
    b = '1101010101';
    c = '11101010100'
console.log(addBinary(a, b));