/**
 * Created by musteryu on 16/5/1.
 */
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }

    public static TreeNode fromArray(String[] arr) {
        if (arr.length < 2) return null;
        if (!arr[1].equals("#")) return insert(new TreeNode(Integer.parseInt(arr[1])), arr, 1);
        else return null;
    }

    private static TreeNode insert(TreeNode root, String[] arr, int index) {
        if (root == null) return null;
        if (index >= arr.length) return null;
        TreeNode left = null, right = null;
        if (2 * index < arr.length && !arr[2 * index].equals("#")) {
            left = new TreeNode(Integer.parseInt(arr[2 * index]));
        }
        root.left = insert(left, arr, 2 * index);
        if (2 * index + 1 < arr.length && !arr[2 * index + 1].equals("#")) {
            right = new TreeNode(Integer.parseInt(arr[2 * index + 1]));

        }
        root.right = insert(right, arr, 2 * index + 1);
        return root;
    }
}
