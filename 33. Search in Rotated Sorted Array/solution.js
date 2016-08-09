/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

/* low speed version
var search = function(nums, target) {
  var i, len = nums.length;
  if (target >= nums[0]) {
    for (i = 0; i < nums.length; i++) {
      if (nums[i] === target) return i;
      if (nums[i] > target) break;
    }
    return -1;
  } else if (target <= nums[len - 1]) {
    for (i = len - 1; i >= 0; i--) {
      if (nums[i] === target) return i;
      if (nums[i] < target) break;
    }
    return -1;
  } else {
    return -1;
  }
}; */

var search = function(nums, target) {
  var i, len = nums.length,
    maxIndex;
  var binarySearch = function(nums, target, low, high) {
    var middle;
    while (low <= high) {
      middle = Math.floor((low + high) / 2);
      if (target > nums[middle]) low = middle + 1;
      else if (target < nums[middle]) high = middle - 1;
      else return middle;
    }
    return -1;
  }
  for (i = 0; i < len - 1; i++) {
    if (nums[i + 1] < nums[i]) maxIndex = i;
  }
  maxIndex = maxIndex === undefined ? len - 1 : maxIndex;

  if (target >= nums[0]) return binarySearch(nums, target, 0, maxIndex);
  if (target <= nums[len - 1]) return binarySearch(nums, target, maxIndex + 1, len - 1);
  return -1;
};

nums = [3, 1];
target = 1;
console.log(search(nums, target));