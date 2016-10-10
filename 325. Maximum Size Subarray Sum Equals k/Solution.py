class Solution(object):
    def maxSubArrayLen(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        sums, cache, maxLen = 0, {0:0}, 0
        for i, num in enumerate(nums):
            sums += num
            if sums - k in cache:
                maxLen = max(maxLen, i - cache[sums-k]+1)
            if sums not in cache:
                cache[sums] = i + 1
        return maxLen