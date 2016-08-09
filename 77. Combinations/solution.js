/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function (n, k) {
    var copy = function (arr) {
        var r = [];
        for (var i of arr)
            r.push(i);
        return r;
    };
    var results = [], i, j, resultsTmp, r;
    for (i = 0; i < k; i++) {
        if (results.length === 0) {
            for (j = 1; j <= n; j++) {
                results.push([j]);
            }
        } else {
            resultsTmp = [];
            while (results.length > 0) {
                r = results.shift();
                for (j = r[r.length-1] + 1; j <= n; j++) {
                    resultsTmp.push(copy(r).concat([j]));
                }
            }
            results = resultsTmp;
        }
    }
    return results;
};

console.log(combine(10, 3));