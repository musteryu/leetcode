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
var postorderTraversal = function(root) {
    var vals = [];
    var postorder = function(root) {
        if (root == null) return;
        postorder(root.left);
        postorder(root.right);
        vals.push(root.val);
    };
    postorder(root);
    return vals;
};
