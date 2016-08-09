/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    var last = 1, curr = 2, len = nums.length;
    for (;curr < len; curr++) {
        if (nums[curr] !== nums[last] || nums[last] !== nums[last-1]) {
            nums[++last] = nums[curr];
        }
    }
    return last++;
};

var nums = [1, 1, 1, 2, 2, 3, 3];
console.log(removeDuplicates(nums));
console.log(nums);