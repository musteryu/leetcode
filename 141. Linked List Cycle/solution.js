/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    var slow = head, fast = head;
    while (slow !== null && fast !== null) {
        slow = slow.next;
        fast = fast.next;
        if (fast === null) return false;
        else fast = fast.next;
        if (slow === fast) return true;
    }
    return false;
};