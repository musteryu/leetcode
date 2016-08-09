/**
 * Created by musteryu on 16/5/3.
 */
public class Solution {
    TreeNode first = null, second = null, pre = null;
    public void recoverTree(TreeNode root) {
        if (root == null) return;
        dfs(root);
        swap(first, second);
    }
    
    private void dfs(TreeNode root) {
        if (root.left != null) dfs(root.left);
        if (pre != null && pre.val > root.val) {
            if (first == null) first = pre;
            if (first != null) second = root;
        }
        pre = root;
        if (root.right != null) dfs(root.right);
    }
    
    private void swap(TreeNode a, TreeNode b) {
        if (a == null && b == null) return;
        int tmp = a.val;
        a.val = b.val;
        b.val = tmp;
    }
}
