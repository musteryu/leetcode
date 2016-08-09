/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
  var elem;
  var cache = [];
  while (nums.length !== 0) {
    elem = nums.pop();
    if (elem !== val) {
      cache.push(elem);
    }
  }
  while (cache.length !== 0) {
    nums.push(cache.pop())
  }
  return nums.length;
};