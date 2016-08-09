class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        if str == '': return 0
        start = 0
        strLen = len(str)
        while str[start] == ' ' and start < strLen:
            start += 1
        if start == strLen: return 0
        if str[start] == '-':
            sign = -1
            start += 1
        elif str[start] == '+':
            sign = 1
            start += 1
        elif self.valid(str[start]):
            sign = 1
        else:
            return 0
        result = 0
        for i in range(start, len(str)):
            if self.valid(str[i]):
                result = result * 10 + self.toi(str[i])
            else: break
        if result > 2 ** 31 - 1:
            return 2147483647 if sign == 1 else -2147483648
        else: return result * sign
    
    def valid(self, char):
        return False if char < '0' or char > '9' else True

    def toi(self, char):
        return ord(char) - ord('0')

    

if __name__ == '__main__':
    import sys
    # testStr = sys.argv[1]
    testStr = "    010"
    print Solution().myAtoi(testStr)
