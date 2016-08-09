/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
  var si = 0,
    pi = 0,
    sStar = 0, // sStar 标记当前*段处理的其实位置
    pStar = -1, // pStar 标记当前最后一个星号的位置
    sLen = s.length,
    pLen = p.length;
  while (si < sLen) {
    if (si < sLen && pi < pLen && (s[si] === p[pi] || p[pi] === '?')) {
      si++;
      pi++;
    } else if (pi < pLen && p[pi] === '*') {
      pStar = pi;
      sStar = si;
      pi = pStar + 1;
    } else if (pStar != -1) {
      pi = pStar + 1;
      sStar += 1;
      si = sStar;
    } else return false;
  }
  while (pi < pLen && p[pi] === '*') pi += 1;
  return pi === pLen;
};
var s = 'ababab';
var p = '**ab*b';
console.log(isMatch(s, p));