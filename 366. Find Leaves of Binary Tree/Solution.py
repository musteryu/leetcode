# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):

    def findLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        labels = collections.defaultdict(list)

        def dfs(root):
            if root is None:
                return -1
            root_label = max(dfs(root.left), dfs(root.right)) + 1
            labels[root_label].append(root.val)
            return root_label

        dfs(root)
        res = []
        for i in range(0, len(labels)):
            res.append(labels[i])
        return res
