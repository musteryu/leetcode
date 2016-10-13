class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        prod = [1] * (n + 1)
        for num in range(2, n+1):
            for l in range(1, num / 2 + 1):
                r = num - l
                prod[num] = max(prod[num], max(prod[l], l) * max(prod[r], r))
        return prod[n]
