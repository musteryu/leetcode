class Solution(object):

    """
    Given n pairs of parentheses, write a function to generate
    all combinations of well-formed parentheses.
    For example, given n = 3, a solution set is:
    "((()))", "(()())", "(())()", "()(())", "()()()"
    """

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = []

        # import pdb
        # pdb.set_trace()

        for _ in range(2 * n):
            if not result:
                result.append(('(', n - 1, n, 1))
                # number of left left parenthesis, left right parenthesis,
                # stack storage of left parenthesis
                continue
            tmp = []
            while len(result) > 0:
                r = result.pop()
                if r[1] > 0:
                    tmp.append((r[0] + '(', r[1] - 1, r[2], r[3] + 1))
                if r[2] > 0 and r[3] > 0:
                    tmp.append((r[0] + ')', r[1], r[2] - 1, r[3] - 1))
            result = tmp
        return [a for a, _, _, _ in result]


if __name__ == '__main__':
    so = Solution()
    print so.generateParenthesis(3)
