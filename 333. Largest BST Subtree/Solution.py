# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def largestBSTSubtree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(root):
            if root is None:
                return True, (float('inf'), -float('inf')), 0
            lbst, lrange, lcnt = dfs(root.left)
            rbst, rrange, rcnt = dfs(root.right)
            if lbst and rbst and lrange[1] < root.val < rrange[0]:
                return True, (min(lrange[0], root.val), max(rrange[1], root.val)), lcnt + rcnt + 1
            return False, None, max(lcnt, rcnt)
        return dfs(root)[2]