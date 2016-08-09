/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    var numsLen = nums.length;
    if (numsLen == 0) return null;
    var min = nums[0];
    for (var i = 1; i < numsLen; i++) {
        if (nums[i] < nums[i-1]) return Math.min(min, nums[i]);
    }
    return min;
};