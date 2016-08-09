/**
 * Created by musteryu on 16/5/3.
 */
public class Solution {
    public boolean isValidBST(TreeNode root) {
        return isValid(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private boolean isValid(TreeNode node, int min, int max) {
        if (node == null) return true;
        if (max < min) return false;
        if (node.val < min || node.val > max) return false;
        boolean v = true;
        if (node.left != null) {
            v &= (node.val != Integer.MIN_VALUE) && isValid(node.left, min, node.val-1);
            if (!v) return v;
        }
        if (node.right != null) {
            v &= (node.val != Integer.MAX_VALUE) && isValid(node.right, node.val+1, max);
            if (!v) return v;
        }
        return v;
    }

    public static void main(String[] args) {
        TreeNode root = TreeNode.fromArray(new String[]{"#","2147483647"});
        System.out.print(new Solution().isValidBST(root));
    }

}
