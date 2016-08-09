import java.util.ArrayList;
import java.util.List;

/**
 * Created by musteryu on 16/5/1.
 */
public class Solution {

    public List<TreeNode> generateTrees(int n) {
        if (n < 1) return new ArrayList<TreeNode>();
        return generateTrees(1, n);
    }

    private List<TreeNode> generateTrees(int beg, int end) {
        List<TreeNode> trees = new ArrayList<>();
        if (beg > end) {
            trees.add(null);
        }
        for (int i = beg; i <= end; i++) {
            List<TreeNode> left = generateTrees(beg, i-1);
            List<TreeNode> right = generateTrees(i+1, end);
            for (TreeNode l: left) {
                for (TreeNode r: right) {
                    TreeNode root = new TreeNode(i);
                    root.left = l;
                    root.right = r;
                    trees.add(root);
                }
            }
        }
        return trees;
    }
}
