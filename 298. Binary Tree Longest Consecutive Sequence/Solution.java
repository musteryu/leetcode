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
    private int max = 0;
    private void length(TreeNode node, int curr, int target) {
        if (node == null) return;
        if (node.val == target) ++curr;
        else curr = 1;
        max = Math.max(curr, max);
        length(node.left, curr, node.val + 1);
        length(node.right, curr, node.val + 1);
    }
    public int longestConsecutive(TreeNode root) {
        if (root == null) return 0;
        length(root, 0, root.val);
        return max;
    }
}