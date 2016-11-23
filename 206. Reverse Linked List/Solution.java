/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode top = null;
        while (head != null) {
            ListNode tmp = head.next;
            head.next = top;
            top = head;
            head = tmp;
        }
        return top;
    }
}