/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function(nums) {
    var dfs = function(start, end) {
        if (start >= end) return null;
        var mid = Math.floor((start + end) / 2);
        var root = new TreeNode(nums[mid]);
        root.left = dfs(start, mid);
        root.right = dfs(mid+1, end);
        return root;
    };
    return dfs(0, nums.length);
};