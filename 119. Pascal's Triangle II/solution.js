/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function(rowIndex) {
    if (rowIndex === 0) return [1];
    var last = [1], curr, len;
    for (var i = 0; i < rowIndex; i++) {
        len = last.length;
        curr = [1];
        if (last.length > 1) {
            for (var j = 1; j < len; j++)
                curr.push(last[j] + last[j-1]);
        }
        curr.push(1);
        last = curr;
    }
    return last;
};