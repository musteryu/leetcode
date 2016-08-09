/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    var ans = 0;
    for (var i = 0; i < 32; i++) {
        var sum = 0;
        for (var j = 0, len = nums.length; j < len; j++) {
            if ((nums[j] >> i) & 1 === 1) {
                sum ++;
                sum %= 3;
            }
        }
        if (sum !== 0) ans |= sum << i;
    }
    return ans;
};