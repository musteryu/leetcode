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
    while (root !== null) {
        var head = root;
        var cursor = root;
        var last = null;
        while (cursor !== null) {
            if (cursor.left && cursor.right)
                cursor.left.next = cursor.right;
            if (last) last.next = cursor.left || cursor.right;
            last = cursor.right || cursor.left || last;
            cursor = cursor.next;
        }
        while (head !== null && !(head.left || head.right))
            head = head.next;
        root = (head !== null) ? head.left || head.right : head;
    }
};