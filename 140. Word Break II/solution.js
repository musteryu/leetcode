/**
 * @param {string} s
 * @param {set<string>} wordDict
 *   Note: wordDict is a Set object, see:
 *   https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Set
 * @return {string[]}
 */
var wordBreak = function(s, wordDict) {
    var sLen = s.length;
    var dp = new Array(sLen + 1).fill().map((e, i) => []);
    dp[0] = [-1];
    var maxWordLen = ((wordDict) => {
        var max = 0;
        wordDict.forEach((e, i) => max = Math.max(e.length, max));
        return max;
    })(wordDict);
    for (var i = 1; i < sLen + 1; i++) {
        for (var j = Math.max(0, i - maxWordLen); j < i; j++) {
            if (wordDict.has(s.substring(j, i)) && dp[j].length > 0)
                dp[i].push(j);
        }
    }
    var results = [];
    var dfs = function(accumulated, current) {
        if (current.length === 1 && current[0] === -1) {
            results.push(Array.from(accumulated));
            return;
        }
        for (node of current) {
            accumulated.unshift(node);
            dfs(accumulated, dp[node]);
            accumulated.shift();
        }
    };
    dfs([sLen], dp[sLen]);
    return results.map((path, index) => {
        var result = [];
        for (var i = 0, pathLen = path.length; i < pathLen - 1; i++) {
            result.push(s.substring(path[i], path[i+1]));
        }
        return result.join(' ');
    });
};