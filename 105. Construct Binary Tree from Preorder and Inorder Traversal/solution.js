/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    var index = [];
    var i;
    for (i = 0; i < inorder.length; i++) {
        index[inorder[i]] = i;
    }
    var build = function(inorder, start, end) {
        if (start >= end) return null;
        var head = preorder.shift();
        if (head !== undefined) {
            var node = new TreeNode(head);
            var rootIndex = index[head];
            node.left = build(inorder, start, rootIndex);
            node.right = build(inorder, rootIndex+1, end);
            return node;
        }
        return null;
    }
    return build(inorder, 0, inorder.length);
};