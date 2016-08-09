/**
 * @param {string} str
 * @returns {string}
 */
var reverseWords = function(str) {
    str.trim().split(/ +/).reverse().join(' ');
};