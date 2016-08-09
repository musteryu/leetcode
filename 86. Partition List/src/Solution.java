/**
 * Created by musteryu on 16/4/28.
 */
public class Solution {
    public static class ListNode {
        int val;
        ListNode next;
        public ListNode(int x) { val = x; }
    }

    public ListNode partition(ListNode head, int x) {
        ListNode less = null, larger = null, curr = head, lessHead, largerHead;
        while ((less == null || larger == null) && curr != null) {
            if (less == null && curr.val < x) {
                less = curr;
            } else if (larger == null && curr.val >= x) {
                larger = curr;
            }
            curr = curr.next;
        }
        lessHead = less;
        largerHead = larger;
        if (less == null || larger == null || larger.next == null) return head;
        curr = head;
        while (curr != null) {
            if (curr == less || curr == larger) {
                // do nothing
            } else if (curr.val < x) {
                less.next = curr;
                less = less.next;
            } else if (curr.val >= x) {
                larger.next = curr;
                larger = larger.next;
            }
            curr = curr.next;
        }
        less.next = largerHead;
        larger.next = null;
        return lessHead;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1), ptr = head;
        ptr.next = new ListNode(4); ptr = ptr.next;
        ptr.next = new ListNode(3); ptr = ptr.next;
        ptr.next = new ListNode(2); ptr = ptr.next;
        ptr.next = new ListNode(5); ptr = ptr.next;
        ptr.next = new ListNode(2); ptr = ptr.next;
        ptr.next = null;

        ListNode p = new Solution().partition(head, 3);
        while (p.next != null) {
            System.out.print(p.val + "->");
            p = p.next;
        }
        System.out.print(p.val);
    }
}
