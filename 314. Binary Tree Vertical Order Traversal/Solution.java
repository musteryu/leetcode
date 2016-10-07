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
    public List<List<Integer>> verticalOrder(TreeNode root) {
        if (root == null) return new LinkedList<>();
        Map<Integer, LinkedList<Integer>> cache = new HashMap<>();
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        Queue<Pair> currLevel = new LinkedList<Pair>();
        currLevel.offer(new Pair(root, 0));
        int size = currLevel.size();
        while (size != 0) {
            for (int i = 0; i < size; ++i) {
                Pair pair = currLevel.poll();
                int offset = pair.offset;
                TreeNode node = pair.node;
                if (!cache.containsKey(offset)) {
                    cache.put(offset, new LinkedList<Integer>());
                    min = Math.min(min, offset);
                    max = Math.max(max, offset);
                }
                cache.get(offset).addLast(node.val);
                if (node.left != null)
                    currLevel.offer(new Pair(node.left, offset-1));
                if (node.right != null)
                    currLevel.offer(new Pair(node.right, offset+1));
            }
            size = currLevel.size();
        }
        List<List<Integer>> res = new LinkedList<>();
        for (int i = min; i <= max; ++i) {
            res.add(cache.get(i));
        }
        return res;
    }

    private class Pair {
        TreeNode node;
        int offset;
        Pair(TreeNode node_, int offset_) {
            node = node_;
            offset = offset_;
        }
    }
}