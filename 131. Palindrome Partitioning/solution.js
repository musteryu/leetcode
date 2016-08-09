/**
 * @param {string} s
 * @return {string[][]}
 */
var partition = function(s) {
    var isPalindrome = function(s, low, high) {
        while (low < high && s[low] === s[--high]) low++;
        return low >= high;
    };

    var dfs = function(s, low, ret, vector) {
        var high = s.length;
        if (low >= high) ret.push(Array.from(vector));
        for (var i = low + 1; i <= high; i++) {
            if (isPalindrome(s, low, i)) {
                vector.push(s.substring(low, i));
                dfs(s, i, ret, vector);
                vector.pop();
            }
        }
    };

    var ret = [];
    var vector = [];
    dfs(s, 0, ret, vector);
    return ret;
};