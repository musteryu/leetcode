/**
 * @param {number[]} nums
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number[]}
 */
var sortTransformedArray = function (nums, a, b, c) {
    if (a == 0) {
        var res = nums.map(transform(a, b, c));
        return b < 0 ? res.reverse() : res;
    }
    var mid = - b / (2 * a);
    var i;
    for (i = 1, len = nums.length; i < len; ++i) {
        if (nums[i] >= mid && nums[i-1] < mid) break;
    }
    nums = nums.map(transform(a, b, c));
    var res = new Array(nums.length);
    var top = 0;
    if (a < 0) {
        var l = 0, r = nums.length - 1;
        while (l < i && r >= i) {
            if (nums[l] < nums[r]) {
                res[top++] = nums[l++];
            } else {
                res[top++] = nums[r--];
            }
        }
        while (l < i) res[top++] = nums[l++];
        while (r >= i) res[top++] = nums[r--];
    } else {
        var l = i - 1, r = i;
        while (l >= 0 && r < nums.length) {
            if (nums[l] < nums[r]) {
                res[top++] = nums[l--];
            } else {
                res[top++] = nums[r++];
            }
        } 
        while (l >= 0) res[top++] = nums[l--];
        while (r < nums.length) res[top++] = nums[r++];
    }
    return res;
};

/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 */
var transform = function (a, b, c) {
    return function (num) {
        if (a == 0) return b * num + c;
        else return a * num * num + b * num + c;
    }
}