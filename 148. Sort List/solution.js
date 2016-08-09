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
var sortList = function(head) {
    var sort = function(head) {
        if (head === null || head.next === null) return {head: head, tail: head};

        var preLess = new ListNode(-1), less = preLess,
            preLarger = new ListNode(-1), larger = preLarger,
            preEq = new ListNode(-1), eq = preEq,
            ptr = head;
        while (ptr !== null) {
            if (ptr.val < head.val) {
                less.next = ptr;
                less = less.next;
            } else if (ptr.val > head.val) {
                larger.next = ptr;
                larger = larger.next;
            } else {
                eq.next = ptr;
                eq = eq.next;
            }
            ptr = ptr.next;
        }
        less.next = larger.next = eq.next = null;
        var sortedLessList = sort(preLess.next);
        var sortedLargerList = sort(preLarger.next);
        var sortedEqList = {head: preEq.next, tail: eq};
        if (sortedLessList.head === null) {
            if (sortedLargerList.head === null) {
                return sortedEqList;
            } else {
                sortedEqList.tail.next = sortedLargerList.head;
                return {head: sortedEqList.head, tail: sortedLargerList.tail};
            }
        } else {
            if (sortedLargerList.head === null) {
                sortedLessList.tail.next = sortedEqList.head;
                return {head: sortedLessList.head, tail: sortedEqList.tail};
            } else {
                sortedLessList.tail.next = sortedEqList.head;
                sortedEqList.tail.next = sortedLargerList.head;
                return {head: sortedLessList.head, tail: sortedLargerList.tail};
            }
        }
    };

    var sorted = sort(head);
    console.log(sorted);
    return sorted.head;
};