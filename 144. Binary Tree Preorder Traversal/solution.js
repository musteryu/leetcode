/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var preorderTraversal = function(root) {
    var vals = [];
    var preorder = function(root) {
        if (root === null || root === undefined) return;
        vals.push(root.val);
        preorder(root.left);
        preorder(root.right);
    };

    preorder(root);
    return vals;
};
