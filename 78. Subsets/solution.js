/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    nums.sort((a, b) => a - b);
    var result = [[]], i, r, num;
    for (num of nums) {
        r = [];
        for (i of result) {
            r.push(i.concat([num]));
        }
        result = result.concat(r);
    }
    return result;
};