/**
 * Definition for a binary tree node.
 * function TreeNode(val) {No
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumNumbers = function(root) {
    const dfs = (root, lastVal) => {
        if (root === null) return 0;
        const next = dfs(root.left, 10 * (lastVal + root.val)) + dfs(root.right, 10 * (lastVal + root.val));
        if (next === 0) return lastVal + root.val;
        else return next;
    }

    return dfs(root, 0);
};