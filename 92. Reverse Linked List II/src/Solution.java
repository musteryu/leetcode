import java.util.Arrays;
import java.util.List;

/**
 * Created by musteryu on 16/5/1.
 */
public class Solution {

    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (m == n) return head;
        ListNode preHead = new ListNode(0), pre = preHead, beg = head, end = head, post;
        preHead.next = head;
        for (int i = 1; i < m; i++) {
            pre = beg;
            beg = beg.next;
        }
        for (int i = 1; i < n; i++) {
            end = end.next;
        }
        pre.next = end;
        post = end.next;
        reverseAndReturnEnd(beg, end).next = post;
        return preHead.next;
    }

    private ListNode reverseAndReturnEnd(ListNode beg, ListNode end) {
        if (beg == end) return end;
        reverseAndReturnEnd(beg.next, end).next = beg;
        return beg;
    }

    public static void main(String[] args) {
        ListNode head = ListNode.fromArray(new int[]{1, 2, 3, 4, 5, 6});
        ListNode r = new Solution().reverseBetween(head, 1, 5);

        while (r != null) {
            System.out.print(r.val + " ");
            r = r.next;
        }
    }
}
