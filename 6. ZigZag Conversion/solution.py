class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        result = []
        halfWidth = numRows-1

        if s == "":
            return s

        if numRows == 1:
            return s
            
        for row in range(numRows):
            if row == 0 or row == halfWidth:
                result += s[row::2 * halfWidth]
            else:
                tmp = []
                i = row
                leftStep = 2 * (halfWidth - row)
                rightStep = 2 * (row)
                leftTurn = True
                while i < len(s):
                    tmp.append(s[i])
                    if leftTurn:
                        i += leftStep
                    else:
                        i += rightStep
                    leftTurn = not leftTurn
                result += tmp

        return "".join(result)


if __name__ == '__main__':
    solution = Solution()
    s = ""
    print solution.convert(s, 1)
