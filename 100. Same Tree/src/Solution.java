/**
 * Created by musteryu on 16/5/3.
 */
public class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p != null && q != null)
            return p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
        else return false;
    }
}
