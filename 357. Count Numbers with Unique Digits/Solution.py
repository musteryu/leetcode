class Solution(object):
    counts = (1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851, 5611771, 8877691)
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        return Solution.counts[n]

for i in range(0, 11):
    print Solution().countNumbersWithUniqueDigits(i)