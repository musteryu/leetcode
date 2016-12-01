/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode plusOne(ListNode head) {
        Stack<ListNode> stack = new Stack<>();
        ListNode copyHead = head;
        while (copyHead != null) {
            stack.push(copyHead);
            copyHead = copyHead.next;
        }
        while (!stack.isEmpty()) {
            ListNode top = stack.pop();
            if (++top.val > 9) {
                top.val -= 10;
            } else return head;
        }
        ListNode newHead = new ListNode(1);
        newHead.next = head;
        return newHead;
    }
}