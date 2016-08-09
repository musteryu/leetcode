class Solution(object):

    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        matchDict = {'(': ')', '[': ']', '{': '}'}
        rightPart = set([')', ']', '}'])
        stack = []
        for c in s:
            if len(stack) == 0:
                stack.append(c)
            elif matchDict.get(stack[len(stack) - 1]) == c:
                stack.pop()
            elif c in rightPart:
                return False
            else:
                stack.append(c)

        if len(stack) == 0:
            return True
        else:
            return False


if __name__ == '__main__':
    so = Solution()
    tests = "([{[]}][]({[]}))"
    print so.isValid(tests)
