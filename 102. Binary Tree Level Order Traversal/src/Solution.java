import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

/**
 * Created by musteryu on 16/5/4.
 */
public class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return new ArrayList<>();
        List<TreeNode> currLevel = new ArrayList<TreeNode>() {{add(root);}};
        List<TreeNode> tmpLevel;
        List<List<Integer>> order = new ArrayList<List<Integer>>() {
            {
                add(new ArrayList<Integer>(){{add(root.val);}});
            }
        };
        List<Integer> tmpOrder;


        while (true) {
            tmpLevel = new ArrayList<>();
            tmpOrder = new ArrayList<>();
            for (TreeNode n : currLevel) {
                if (n.left != null) {
                    tmpLevel.add(n.left);
                    tmpOrder.add(n.left.val);
                }
                if (n.right != null) {
                    tmpLevel.add(n.right);
                    tmpOrder.add(n.right.val);
                }
            }
            if (!tmpOrder.isEmpty()) {
                currLevel = tmpLevel;
                order.add(tmpOrder);
            } else break;
        }
        return order;
    }

    public static void main(String[] args) {
        TreeNode root = TreeNode.fromArray(new String[]{"#", "3", "9", "20", "#", "#", "15", "7"});
        List<List<Integer>> order = new Solution().levelOrder(root);
        order.forEach(l -> {
            l.forEach(i -> System.out.print(i + " "));
            System.out.println();
        });
    }
}
