/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    var d = new Array(word1.length+1).fill().map((e, i) => new Array(word2.length+1));
    var i, j, len1 = word1.length, len2 = word2.length;
    for (i = 0; i <= len1; i++)
        d[i][0] = i;
    for (j = 0; j <= len2; j++)
        d[0][j] = j;
    for (i = 0; i < len1; i++)
        for (j = 0; j < len2; j++)
            d[i+1][j+1] = Math.min(
                d[i][j+1] + 1,
                d[i+1][j] + 1,
                d[i][j] + (word1[i] === word2[j] ? 0 : 1)
            );
    return d[len1][len2];
};

var word1 = 'execution';
var word2 = 'intention';
console.log(minDistance(word1, word2));