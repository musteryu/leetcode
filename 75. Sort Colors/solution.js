/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    var i = -1, j = -1, k = -1, len = nums.length, p;
    for (p = 0; p < len; p++) {
        if (nums[p] === 0) {
            nums[++k] = 2;
            nums[++j] = 1;
            nums[++i] = 0;
        } else if (nums[p] === 1) {
            nums[++k] = 2;
            nums[++j] = 1;
        } else 
            nums[++k] = 2;
        console.log(nums);
    }
    
};

var nums = [1, 1, 0, 2, 0, 2, 1, 0, 2, 1, 0, 1, 2, 2];
console.log(nums);
sortColors(nums);
console.log(nums);