/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    var result = [[1]];
    if (numRows === 0) return [];
    var last, curr, len;
    for (var i = 1; i < numRows; i++) {
        len = result.length;
        last = result[len-1];
        curr = [1];
        if (last.length > 1) {
            for (var j = 1; j < len; j++)
                curr.push(last[j] + last[j-1]);
        }
        curr.push(1);
        result.push(curr);
    }
    return result;
};