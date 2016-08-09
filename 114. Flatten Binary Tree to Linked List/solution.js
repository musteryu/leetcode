/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flatten = function(root) {
    var current;
    var dfs = function(root) {
        if (root === null) return
        current = root
        var left = root.left
        var right = root.right
        if (left !== null) {
            current.right = left
            root.left = null
            dfs(left)
        }
        if (right !== null) {
            current.right = right
            dfs(right)
        }  
    }
    dfs(root)
};