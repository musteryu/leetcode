# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return max(self.rob_root(root))
        
    def rob_root(self, root):
        if root is None:
            return 0, 0
        l_rob, l_unrob = self.rob_root(root.left)
        r_rob, r_unrob = self.rob_root(root.right)
        return root.val + l_unrob + r_unrob, max(l_rob, l_unrob) + max(r_rob, r_unrob)