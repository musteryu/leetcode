/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
  var bsearch = function(nums, target) {
    var low = 0,
      high = nums.length - 1;
    var middle;
    while (low <= high) {
      middle = Math.floor((high + low) / 2);
      if (target > nums[middle]) low = middle + 1;
      else high = middle - 1;
    }
    return low;
  }

  return bsearch(nums, target);

};

var nums = [1, 2, 3, 5, 7];
var target = -1;
console.log(searchInsert(nums, target));