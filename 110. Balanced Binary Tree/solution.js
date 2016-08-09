/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function(root) {
    var height = function(root) {
        if (root === null) return 0;
        var lheight = height(left.height);
        var rheight = height(left.right);
        if (lheight === false || rheight === false || Math.abs(lheight, rheight) > 1)
            return false;
        else return 1 + Math.max(lheight, rheight);
    };
    return height(root) !== false;
};