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
var insertionSortList = function(head) {
    var preHead = new ListNode(-1);
    preHead.next = head;
    var proc = head;
    var top = preHead;
    while (proc !== null) {
        var pointer = preHead;
        var next = proc.next;
        while (pointer.next !== proc && pointer.next.val <= proc.val) {
            pointer = pointer.next;
        }
        if (pointer.next !== proc) {
            proc.next = pointer.next;
            pointer.next = proc;
            top.next = next;
        } else {
            top = proc;
        }
        proc = next;
    }
    var ret = preHead.next;
    preHead.next = null;
    return ret;
};
