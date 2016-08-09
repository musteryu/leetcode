/**
 * Created by musteryu on 16/5/1.
 */
public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }

    public static ListNode fromArray(int[] arr) {
        ListNode head = null, ptr = head;
        for (int elem: arr) {
            if (head == null) {
                head = new ListNode(elem);
                ptr = head;
            } else {
                ptr.next = new ListNode(elem);
                ptr = ptr.next;
            }
        }
        ptr.next = null;
        return head;
    };
}

