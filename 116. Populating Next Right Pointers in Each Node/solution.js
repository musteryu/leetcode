/**
 * Definition for binary tree with next pointer.
 * function TreeLinkNode(val) {
 *     this.val = val;
 *     this.left = this.right = this.next = null;
 * }
 */

/**
 * @param {TreeLinkNode} root
 * @return {void} Do not return anything, modify tree in-place instead.
 */
var connect = function(root) {
    var linkSubtrees = function(left, right) {
        if (left === null || right === null) return
        left.next = right
        linkSubtrees(left.right, right.left)
    }
    var linkTree = function(root) {
        if (root === null) return
        linkSubtrees(root.left, root.right)
        linkTree(root.left)
        linkTree(root.right)
    }
    var linkNull = function(root) {
        if (root === null) return
        root.next = null
        linkNull(root.right)
    }
    linkTree(root)
    linkNull(root)
};


