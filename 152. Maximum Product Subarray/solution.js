/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    var max = -Infinity;
    var low = 0, high = 0;
    var len = nums.length;
    var product = 1;
    while (low < len) {
        while (high < len && nums[high] !== 0) {
            product *= nums[high];
            max = Math.max(max, product);
            high++;
        }
        while (low < high) {
            product /= nums[low];
            if (low !== high - 1) 
                max = Math.max(max, product);
            low++;
        }
        if (high < len && nums[high] === 0) {
            high = low = high + 1;
            max = Math.max(max, 0);
        }
    }
    return max;
};

console.log(maxProduct([-2]));