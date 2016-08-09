/**
 * Created by musteryu on 16/4/25.
 */
public class Solution {
    private static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return null;
        ListNode r = new ListNode(head.val);
        head = head.next;
        ListNode ptr = r;
        while (head != null) {
            if (head.val != ptr.val) {
                ptr.next = head;
                ptr = ptr.next;
            }
            head = head.next;
            ptr.next = null;
        }
        return r;
    }

    public static void main(String[] args) {
        ListNode r = new ListNode(0);
        ListNode ptr = r;
        for (int i = 0; i < 10; i++) {
            ptr.next = new ListNode(i / 2);
            ptr = ptr.next;
        }
        ListNode d = new Solution().deleteDuplicates(r);
        while (d != null) {
            System.out.print(d.val + " ");
            d = d.next;
        }
    }
}
