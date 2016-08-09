/**
 * @param {number[]} nums
 * @return {number[][]}
 */
/** DFS 
var permute = function(nums) {
  var result = [];
  var permutation = function(cursor) {
    if (cursor === nums.length - 1) {
      result.push(nums.slice());
    } else {
      for (var i = cursor, len = nums.length; i < len; i++) {
        rotate(i, cursor);
        permutation(cursor + 1);
        rotate(i, cursor);
      }
    }
  };
  var rotate = function(i, j) {
    var tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  };
  permutation(0);
  return result;
};
*/
/** BFS **/
var permute = function(nums) {
  var result = [nums];
  if (nums.length < 2) return result;
  var pos = 0,
    numLen = nums.length,
    resultLen,
    r;
  var swap = function(arr, i, j) {
    var tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  };
  while (pos < numLen) {
    resultLen = result.length;
    for (var i = 0; i < resultLen; i++) {
      for (var j = pos + 1; j < numLen; j++) {
        r = result[i].slice();
        swap(r, j, pos);
        result.push(r);
      }
    }
    pos++;
  }
  return result;
}
var nums = [1];
// permute(nums);
console.log(permute(nums));