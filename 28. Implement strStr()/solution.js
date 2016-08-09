/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
  var needleLength = needle.length;
  var i, i_tmp, j;
  var len;
  for (i = 0, len = haystack.length; i < len - needleLength + 1; i++) {
    i_tmp = i;
    for (j = 0; j < needleLength; j++) {
      if (haystack[i_tmp] === needle[j]) {
        i_tmp++;
      } else {
        break;
      }
    }
    if (j === needleLength) return i;
  }
  // return (haystack === needle) ? 0 : -1;
  return -1;
};