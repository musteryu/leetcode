/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {TreeNode}
 */
var sortedListToBST = function(head) {
    var current = head;
    var len = 0;
    while (head !== null) {
        len ++;
        head = head.next;
    }
    var dfs = function(begin, end) {
        if (begin >= end) return null;
        var node = new TreeNode(-1); // Meaningless value
        var mid = Math.floor((begin + end) / 2);
        node.left = dfs(begin, mid);
        node.val = current.val;
        current = current.next;
        node.right = dfs(mid+1, end);
        return node;
    };
    return dfs(0, len);
};