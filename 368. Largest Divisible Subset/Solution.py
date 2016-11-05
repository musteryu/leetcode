class Solution(object):

    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums = sorted(nums)
        size = [0] * len(nums)
        aux = [-1] * len(nums)
        for i, n in enumerate(nums):
