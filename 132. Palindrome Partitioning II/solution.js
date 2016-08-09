/**
 * @param {string} s
 * @return {number}
 */
var minCut = function(s) {
    var addSymbol = function(s, symbol) {
        var len = s.length;
        var newStr = new Array(len * 2 + 1);
        var i = 0;
        for (var char of s) {
            newStr[i++] = symbol;
            newStr[i++] = char;
        }
        newStr[i] = symbol;
        return newStr;
    };
    var countPalindrome = function(s) {
        var len = s.length;
        var count = new Array(len).fill(1);
        var mx = 0,
            id = 0;
        for (var i = 1; i < len; i++) {
            count[i] = mx > i ? Math.min(count[2 * id - i], mx - i) : 1;
            while (s[i + count[i]] !== undefined 
                && s[i - count[i]] !== undefined 
                && s[i + count[i]] === s[i - count[i]]) {
                count[i]++;
            }
            if (i + count[i] > mx) {
                mx = i + count[i];
                id = i;
            }
        }
        return count;
    };
    var len = s.length;
    var dp = new Array(len + 1).fill().map((e, i) => i);
    var ii, jj, mid;
    var count = countPalindrome(addSymbol(s, '#'));
    for (var i = 1; i < len + 1; i++) {
        for (var j = 0; j < i; j++) {
            ii = 2 * i - 1;
            jj = 2 * j + 1;
            mid = i + j;
            if (ii - mid < count[mid]) {
                dp[i] = Math.min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[len] - 1;
};

console.log(minCut('aaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa'));
