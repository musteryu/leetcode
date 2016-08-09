/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
/*
var searchRange = function(nums, target) {
  var binarySearch = function(nums, target, low, high) {
    var middle;
    while (low <= high) {
      middle = Math.floor((low + high) / 2);
      if (target < nums[middle]) high = middle - 1;
      else if (target > nums[middle]) low = middle + 1;
      else return middle;
    }
    return -1;
  }
  if (nums.length === 0) return -1;
  var len = nums.length;
  var middleIndex = binarySearch(nums, target, 0, len - 1);
  if (middleIndex === -1) return [-1, -1];
  var lowIndex, highIndex;
  for (lowIndex = middleIndex - 1; lowIndex >= 0; lowIndex--) {
    if (nums[lowIndex] !== nums[middleIndex]) break;
  }
  for (highIndex = middleIndex + 1; highIndex < len; highIndex++) {
    if (nums[highIndex] !== nums[middleIndex]) break;
  }
  return [lowIndex + 1, highIndex - 1];
};
*/

/* a more elegant solution */
var searchRange = function(nums, target) {
  var binarySearchLeft = function(nums, target) {
    var low = 0,
      high = nums.length - 1;
    var middle;
    while (low <= high) {
      middle = Math.floor((low + high) / 2);
      if (target > nums[middle]) low = middle + 1;
      else high = middle - 1;
    }
    return low;
  };
  var binarySearchRight = function(nums, target) {
    var low = 0,
      high = nums.length - 1;
    var middle;
    while (low <= high) {
      middle = Math.floor((low + high) / 2);
      if (target >= nums[middle]) low = middle + 1;
      else high = middle - 1;
    }
    return high;
  };
  left = binarySearchLeft(nums, target);
  right = binarySearchRight(nums, target);
  return (left <= right) ? [left, right] : [-1, -1];
}

var nums = [6, 7, 8, 8, 8, 9];
var target = 8;
console.log(searchRange(nums, target));