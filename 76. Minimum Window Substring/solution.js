/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    var map = {},
        start = 0, end = 0, 
        len = s.length,
        minLen = len + 1, 
        minStart = 0, 
        count = t.length;
    for (var char of t) {
        map[char] = (map[char] + 1) || 1;
    }
    while (end < len) {
        if (map[s[end]] > 0) {
            count--;
        }
        if (map[s[end]] !== undefined)
            map[s[end]]--;
        while (count === 0 && start <= end) {
            if ((end - start + 1) < minLen) {
                minLen = end - start + 1;
                minStart = start;
            }
            if (map[s[start]] !== undefined) {
                map[s[start]] ++;
            }
            if (map[s[start]] > 0) {
                count++;
            }
            start++;
        }
        end++;
    }
    if (minStart + minLen > len) return "";
    else return s.substr(minStart, minLen);
};

var s = "babb";
var t = "bab";
console.log(minWindow(s, t));