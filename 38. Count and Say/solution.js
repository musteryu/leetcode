/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
  return (function() {
    var count = function(nums) {
      var
        len, i, count = 1,
        result = [];
      len = nums.length;
      for (i = 0; i < len; i++) {
        if (nums[i + 1] === nums[i]) {
          count++;
        } else {
          result.push(count);
          result.push(nums[i]);
          count = 1;
        }
      }

      return result.join('');
    };

    if (n === 1) return '1';
    if (n > 1) return count(countAndSay(n - 1));
  }());
};

var n = 6;
console.log(countAndSay(n));