class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        preorder = preorder.split(',')
        stack = []
        for node in preorder:
            stack.append(node)
            while (len(stack) > 2 and stack[-2] == stack[-1] == '#' and stack[-3] != '#'):
                stack.pop()
                stack.pop()
                stack[-1] = '#'
        return True if len(stack) == 1 and stack[0] == '#' else False
