/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
  var last, i;
  for (last = s.length - 1; last >= 0; last--) {
    if (s[last] !== ' ') break;
  }
  if (last < 0) return 0;
  for (i = last; i >= 0; i--) {
    if (s[i] === ' ') break;
  }
  return last - i;
};
var s = "  ";
console.log(lengthOfLastWord(s));