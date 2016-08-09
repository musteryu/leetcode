import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

/**
 * Created by musteryu on 16/5/1.
 */
public class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        List<Integer> t = new LinkedList<Integer>();
        if (root == null) return t;
        TreeNode top;
        do {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
            top = stack.pop();
            root = top.right;
            t.add(top.val);
        } while (!(stack.isEmpty() && root == null));
        return t;
    }

    public static void main(String[] args) {
        TreeNode root = TreeNode.fromArray(new char[]{'#', '1', '2', '3', '4', '5', '6', '7'});
        LinkedList<Integer> t = (LinkedList<Integer>) new Solution().inorderTraversal(root);
        CollectionUtil.printIterable(t, ", ");
    }
}
