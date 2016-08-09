class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        digit = 0
        xcopy = x
        while xcopy > 0:
            xcopy /= 10
            digit += 1
        hi = 10 ** (digit - 1)
        lo = 1
        while hi >= lo:
            if (x / hi) % 10 == x % (lo * 10) / lo:
                hi /= 10
                lo *= 10
            else:
                return False
        return True

if __name__ == '__main__':
    f = open('test.txt', 'r')
    so = Solution()
    for line in f:
        testnum = int(line)
        print so.isPalindrome(testnum)
