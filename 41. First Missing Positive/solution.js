/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
  var i, len = nums.length,
    tmp;
  if (nums.length === 0) return 1;
  for (i = 0; i < len; i++) {
    while (nums[i] > 0 && nums[i] !== i + 1) {
      tmp = nums[i];
      if (nums[tmp - 1] === tmp) break;
      nums[i] = nums[tmp - 1];
      nums[tmp - 1] = tmp;
    }
  }
  for (i = 0; i < len; i++) {
    if (nums[i] !== i + 1) return i + 1;
  }
  return len + 1;
};

console.log(firstMissingPositive([1]))