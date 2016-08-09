/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
  var i,
    len,
    stack = [];
  if (s === '') {
    return 0;
  }

  var procStackTop = function(stack, cumulative) {
    var top = stack.pop();
    var nextToTop;
    if (top === ')') {
      nextToTop = stack.pop();
      if (nextToTop === '(') {
        stack.push(2 + cumulative);
      } else if (typeof nextToTop === 'number' && stack[stack.length - 1] === '(') {
        stack.push(top);
        procStackTop(stack, cumulative + nextToTop);
      } else if (nextToTop !== undefined) {
        stack.push(nextToTop);
        stack.push(top);
      } else {
        stack.push(top);
      }
    } else {
      stack.push(top);
    }
    if (typeof stack[stack.length - 2] === 'number' && typeof stack[stack.length - 1] === 'number') {
      stack[stack.length - 2] += stack.pop();
    }
  };

  for (i = 0, len = s.length; i < len; i++) {
    stack.push(s[i]);
    procStackTop(stack, 0);
  }
  var results = stack.filter(x => typeof x === 'number');
  if (results.length === 0)
    return 0
  return Math.max.apply(this, results);
}


var s = "()))))))()()()";
var r = longestValidParentheses(s);
console.log(r);