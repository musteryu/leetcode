/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var numDistinct = function(s, t) {
    var row = s.length + 1, col = t.length + 1
    var i, j
    var n = new Array(row);
    for (i = 0; i < row; i++) {
        n[i] = new Array(col).fill(0)
        n[i][0] = 1
    }
    for (i = 0; i < row - 1; i++) {
        for (j = 0; j < col - 1; j++) {
            if (s[i] === t[j]) {
                n[i+1][j+1] = n[i][j] + n[i][j+1]
            } else {
                n[i+1][j+1] = n[i][j+1]
            }
        }
    }
    return n[s.length][t.length]
};

var numDistinct = function(s, t) {
    var sLength = s.length, tLength = t.length
    var si, ti
    var n = new Array(tLength+1).fill(0)
    n[0] = 1
    for (si = 0; si < sLength; si++) {
        for (ti = 0; ti < tLength; ti++) {
            if (s.charCodeAt(si) === t.charCodeAt(ti))
                n.push(head + n[0])
            else
                n.push(n[0])
            head = n.shift()
        }  
    }
    return n.pop()
};