/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    var set = new Set(nums);
    var max = 0;
    for (var num of nums) {
        if (set.size === 0) break;
        if (set.has(num)) {
            var larger = num, less = num;
            var count = 1;
            set.delete(num);
            while (set.delete(++larger)) {
                count++;
            }
            while (set.delete(--less)) {
                count++;
            }
            max = Math.max(max, count);
        } 
    }
    return max;
};