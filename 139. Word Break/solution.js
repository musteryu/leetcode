/**
 * @param {string} s
 * @param {set<string>} wordDict
 *   Note: wordDict is a Set object, see:
 *   https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Set
 * @return {boolean}
 */
var wordBreak = function(s, wordDict) {
    var dp = new Array(s.length + 1).fill(false);
    dp[0] = true;
    var len = s.length;
    var maxLen = (function(set) {
        var max = 0;
        set.forEach((e, i) => {
            max = Math.max(e.length, max);
        });
        return max;
    }(wordDict));
    for (var i = 1; i < len + 1; i++) {
        for (var j = i-1, lower = Math.max(i-1-maxLen, -1); j > lower; j--) {
            if (wordDict.has(s.substring(j, i)) && dp[j])
                dp[i] = true;
        }
    }
    return dp.pop();
};