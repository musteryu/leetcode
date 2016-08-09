/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    var xor = 0;
    for (var num of nums)
        xor ^= num;
    return xor;
};