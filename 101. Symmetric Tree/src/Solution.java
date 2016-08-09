import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

/**
 * Created by musteryu on 16/5/4.
 */
public class Solution {
    public boolean isSymmetric(TreeNode root) {
        return root == null || isSymmetrixIteratively(root.left, root.right);
    }

    private boolean isSymmetrix(TreeNode l, TreeNode r) {
        if (l == null && r == null) return true;
        if (l != null && r != null) {
            if (l.val != r.val) return false;
            if (!isSymmetrix(l.right, r.left)) return false;
            if (!isSymmetrix(l.left, r.right)) return false;
            return true;
        } else {
            return false;
        }
    }

    private boolean isSymmetrixIteratively(TreeNode l, TreeNode r) {
        if (l == null && r == null) return true;
        if (!(l != null && r != null)) return false;
        Queue<TreeNode> lqueue = new LinkedList<>();
        lqueue.add(l);
        Queue<TreeNode> rqueue = new LinkedList<>();
        rqueue.add(r);
        while (!lqueue.isEmpty() && !rqueue.isEmpty()) {
            TreeNode lhead = lqueue.poll();
            TreeNode rhead = rqueue.poll();
            if (lhead != null && rhead != null) {
                if (lhead.val != rhead.val) return false;
                lqueue.add(lhead.left);
                lqueue.add(lhead.right);
                rqueue.add(rhead.right);
                rqueue.add(rhead.left);
            } else if (lhead == null && rhead == null) continue;
            else return false;
        }
        return true;
    }
}
