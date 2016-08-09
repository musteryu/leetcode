/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
  var result = [[]], resultLength;
  var i, j, k, t, r;
  for (i = 0; i < nums.length; i++) {
    resultLength = result.length;
    for (j = 0; j < resultLength; j++) {
      r = result.shift();
      for (k = 0; k < nums.length; k++) {
        if (k > 0 && r[k-1] === nums[i]) break;
        if (r[k] !== undefined) continue;
        t = r.slice();
        t[k] = nums[i];
        result.push(t);
      }
    }
  }
  return result;
};
var nums = [0, 0, 2, 2, 3, 3, 3];
var result = permuteUnique(nums);
console.log(result.length);
// console.log(result);