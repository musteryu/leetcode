import math


class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        dp = [0] * (num + 1)
        n = 1
        while n <= num:
            dp[n] = 1
            n = 2 * n
        step = 2
        for i in range(3, num+1):
            if dp[i] == 0:
                dp[i] = dp[i-step] + 1
            else:
                step = i
        return dp
