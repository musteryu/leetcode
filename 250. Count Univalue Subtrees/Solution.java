/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    private int count = 0;

    private boolean isUnivalSubtree(TreeNode root) {
        boolean isUnval = true;
        if (root.left != null) {
            boolean leftUnival = isUnivalSubtree(root.left) && 
                                 root.val == root.left.val;
            isUnval = isUnval && leftUnival;
        }
        if (root.right != null) {
            boolean rightUnival = isUnivalSubtree(root.right) && 
                                  root.val == root.right.val;
            isUnval = isUnval && rightUnival;
        }
        if (isUnval) count++;
        return isUnval;
    }
    public int countUnivalSubtrees(TreeNode root) {
        count = 0;
        if (root != null) isUnivalSubtree(root); 
        return count;
    }
}