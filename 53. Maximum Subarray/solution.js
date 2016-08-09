/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
  var max = nums[0],
    sum = 0;
  nums.forEach((e, i) => {
    sum += e;
    if (sum > max) max = sum;
    if (sum < 0) sum = 0;
  });
  return max;
};
var nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4];
console.log(maxSubArray(nums));