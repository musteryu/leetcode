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
    private Stack<TreeNode> preStack;
    private Stack<TreeNode> sucStack;
    private void inorder(TreeNode root, double target, boolean reverse, Stack<Integer> stack) {
        if (root == null) return;
        inorder(reverse ? root.right : root.left, target, reverse, stack);
        if (reverse && root.val <= target) return;
        if (!reverse && root.val > target) return;
        stack.push(root.val);
        inorder(reverse ? root.left : root.right, target, reverse, stack);
    }

    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        List<Integer> values = new LinkedList<Integer>();
        Stack<Integer> pre = new Stack<Integer>();
        Stack<Integer> succ = new Stack<Integer>();
        inorder(root, target, false, pre);
        inorder(root, target, true, succ);
        while (k-- > 0) {
            if (pre.empty())
                values.add(succ.pop());
            else if (succ.empty())
                values.add(pre.pop());
            else if (Math.abs((double)pre.peek() - target) < Math.abs((double)succ.peek() - target))
                values.add(pre.pop());
            else
                values.add(succ.pop());
        }
        return values;
    }
}