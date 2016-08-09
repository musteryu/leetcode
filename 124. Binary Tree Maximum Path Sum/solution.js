/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxPathSum = function(root) {
    var map = new Map();
    var sumToRoot = function(root) {
        if (root === null || root === undefined) return 0;
        var s = map.get(root);
        if (s !== undefined) return s; 
        var leftSum = sumToRoot(root.left);
        var rightSum = sumToRoot(root.right);
        s = Math.max(leftSum, rightSum, 0) + root.val;
        map.set(root, s);
        return s;
    };
    var dfs = function(root) {
        var s = root.val;
        s += Math.max(0, sumToRoot(root.left)) + Math.max(0, sumToRoot(root.right));
        if (root.left) s = Math.max(s, dfs(root.left));
        if (root.right) s = Math.max(s, dfs(root.right));
        return s;
    }
    return dfs(root);
};


var maxPathSum = function(root) {
    var maxSum = - Infinity;
    var oneSideMax = function(root) {
        if (root === null) return 0;
        var l = oneSideMax(root.left);
        var r = oneSideMax(root.right);
        maxSum = Math.max(maxSum, Math.max(l, 0) + root.val + Math.max(r, 0));
        return root.val + Math.max(0, l, r);
    }

    oneSideMax(root);
    return maxSum;
}