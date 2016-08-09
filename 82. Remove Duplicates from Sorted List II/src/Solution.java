/**
 * Created by musteryu on 16/4/25.
 */
public class Solution {
    private static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public ListNode deleteDuplicates(ListNode head) {
        ListNode r = new ListNode(0);
        ListNode ptr = r;
        ListNode pre = head;
        ListNode curr = head;
        while (curr != null) {
            while (curr.next != null && curr.next.val == curr.val) {
                curr = curr.next;
            }
            if (curr == pre) {
                ptr.next = pre;
                ptr = ptr.next;
            }
            pre = curr.next;
            curr = pre;
        }
        ptr.next = null;
        return r.next;
    }

    public static void main(String[] args) {
        ListNode l = new ListNode(1);
        ListNode head = l;
        l.next = new ListNode(1);
        l = l.next;
        l.next = new ListNode(1);
        l = l.next;
        l.next = new ListNode(2);
        l = l.next;
        l.next = new ListNode(3);
        l = l.next;
        l.next = new ListNode(4);
        l = l.next;
        l.next = new ListNode(4);
        l = l.next;
        l.next = new ListNode(5);
        l = l.next;
        l.next = null;
        ListNode d = new Solution().deleteDuplicates(head);
        while (d != null) {
            System.out.print(d.val + " -> ");
            d = d.next;
        }
    }
}