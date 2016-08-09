/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    var a = 'a'.charCodeAt(0);
    var z = 'z'.charCodeAt(0);
    var zero = '0'.charCodeAt(0);
    var nine = '9'.charCodeAt(0);
    
    var isAlphaNumeric = function(charCode) {
        return charCode >= a && charCode <= z || charCode >= zero && charCode <= nine;
    };
    var bgn = 0, end = s.length - 1;
    var bgnChar, endChar;
    var lowerStr = s.toLowerCase();
    while (bgn < end) {
        bgnChar = lowerStr.charCodeAt(bgn);
        endChar = lowerStr.charCodeAt(end);
        if (!isAlphaNumeric(bgnChar)) {
            bgn ++;
            continue;
        }
        if (!isAlphaNumeric(endChar)) {
            end --;
            continue;
        }
        if (bgnChar !== endChar) return false;
        bgn ++;
        end --;
    }
    return true;
};