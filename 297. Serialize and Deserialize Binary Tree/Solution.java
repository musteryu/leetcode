/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    private void do_seri(TreeNode root, Queue<String> stream) {
        if (root == null)
            stream.offer("# ");
        else {
            stream.offer(root.val + " ");
            do_seri(root.left, stream);
            do_seri(root.right, stream);
        }
    }

    private TreeNode do_deseri(Queue<String> stream) {
        String top = stream.poll();
        if (top.equals("#")) return null;
        TreeNode node = new TreeNode(Integer.parseInt(top));
        node.left = do_deseri(stream);
        node.right = do_deseri(stream);
        return node;
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        Queue<String> stream = new LinkedList<String>();
        do_seri(root, stream);
        StringBuilder sb = new StringBuilder();
        while (!stream.isEmpty()) {
            sb.append(stream.poll());
        }
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        Queue<String> stream = new LinkedList<String>(Arrays.asList(data.split(" ")));
        return do_deseri(stream);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));