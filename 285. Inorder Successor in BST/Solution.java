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
    private TreeNode dfs(TreeNode node, Stack<TreeNode> inorder, TreeNode p) {
        if (node == null) return null;
        TreeNode v;
        if ((v = dfs(node.left, inorder, p)) != null) return v;
        if (!inorder.empty() && inorder.peek() == p) return node;
        inorder.push(node);
        if ((v = dfs(node.right, inorder, p)) != null) return v;
        return null;
    }
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        return dfs(root, new Stack<TreeNode>(), p);
    }
}