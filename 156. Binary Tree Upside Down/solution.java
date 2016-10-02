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
    private TreeNode upsideDown(TreeNode root) {
        if (root.left == null) return root;
        TreeNode newRoot = upsideDown(root.left);
        newRoot.left = root.right;
        newRoot.right = root;
        root.left = null;
        root.right = null;
        return root;
    }
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        if (root == null || root.left == null) return root;
        TreeNode newRoot = root;
        while (newRoot.left != null) {
            newRoot = newRoot.left;
        }
        upsideDown(root); 
        return newRoot;
    }
}