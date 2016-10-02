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
    private int closest(int a, int b, double target) {
        if (Math.abs((double)a - target) < Math.abs((double)b - target))
            return a;
        else return b;
    }
    public int closestValue(TreeNode root, double target) {
        if (target > root.val && root.right != null) {
            return closest(root.val, closestValue(root.right, target), target);
        }
        if (target < root.val && root.left != null) {
            return closest(root.val, closestValue(root.left, target), target);
        }
        return root.val;
    }
}