/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
    var inIndex = [];
    for (var i = 0; i < inorder.length; i++) {
        inIndex[inorder[i]] = i;
    }
    var build = function(inStart, inEnd, postStart, postEnd) {
        if (postStart >= postEnd) return null;
        var root = new TreeNode(postorder[postEnd-1]);
        var inMid = inIndex[root.val];
        root.left = build(inStart, inMid, postStart, postStart + inMid - inStart);
        root.right = build(inMid+1, inEnd, postStart + inMid - inStart, postEnd-1);
        return root;
    }
    return build(0, inorder.length, 0, postorder.length);
};