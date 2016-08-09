class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x.bit_length() > 32:
            return 0
        result = 0
        sign = -1 if x < 0 else 1
        x *= sign
        while x > 0:
            result = (result * 10) + x % 10
            x /= 10
        
        return 0 if result > 2**31 - 1 else result * sign


if __name__ == '__main__':
    import sys
    testInt = int(sys.argv[1])
    so = Solution()
    print so.reverse(testInt)