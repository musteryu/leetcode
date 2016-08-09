/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function(nums) {
  var
    order = nums.slice().sort((a, b) => a - b),
    i,
    currentFirst, currentFirstIndex, nextFirst, nextFirstIndex,
    subArray,
    noNextPermutation = function(subArray) {
      for (var i = 1, len = subArray.length; i < len; i++) {
        if (subArray[i] > subArray[i - 1]) return false;
      }
      return true;
    };

  for (var i = nums.length - 2; i >= 0; i--) {
    if (noNextPermutation(subArray = nums.slice(i))) {
      continue;
    }
    currentFirst = subArray[0];
    subArray.sort((a, b) => a - b);
    nextFirstIndex = currentFirstIndex = subArray.indexOf(currentFirst);
    while (subArray[++nextFirstIndex] === currentFirst) {};
    if (nextFirstIndex >= subArray.length) continue;
    nextFirst = subArray.splice(nextFirstIndex, 1)[0];
    subArray.sort((a, b) => a - b).unshift(nextFirst);
    for (var j = i; j < nums.length; j++) {
      nums[j] = subArray[j - i];
    }
    return;
  }
  for (var j = 0; j < nums.length; j++) {
    nums[j] = order[j];
  }
};

var nums = [100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1];
var count = 1;
while (count--) {
  nextPermutation(nums)
  console.log(nums);
}