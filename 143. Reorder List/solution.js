/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
    if (head === null || head.next === null) return ;
    var reverse = function(head) {
        var last = head;
        while (last.next !== null) last = last.next;
        var reverseWrap = function(head) {
            if (head !== last) {
                reverseWrap(head.next).next = head;
                head.next = null;
            }
            return head;
        }
        reverseWrap(head);
        return last;
    };
    
    var slow = new ListNode(-1), fast = slow;
    slow.next = head;
    while (slow !== null && fast !== null && fast.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    var left = head, right = reverse(slow.next);
    slow.next = null;
    while (left !== null && right !== null) {
        var leftNext = left.next, rightNext = right.next;
        left.next = right;
        right.next = leftNext;
        left = leftNext;
        right = rightNext;
    }
};

var reorderList = function(head) {
    if (head === null || head.next === null) return;
    var arr = [];
    while (head !== null) {
        arr.push(head);
        head = head.next;
    }
    var left = 0, right = arr.length-1;
    while (left < right) {
        arr[left].next = arr[right];
        arr[right].next = arr[left+1];
        left++;
        right--;
    }
    arr[left].next = null;
}
