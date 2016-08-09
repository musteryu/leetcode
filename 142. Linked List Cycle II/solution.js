/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var detectCycle = function(head) {
    var slow = head, fast = head;
    while (slow !== null && fast !== null && fast.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) {
            while (head !== fast) {
                head = head.next;
                fast = fast.next;
            }
            return head;
        }
    }
    return null;
};