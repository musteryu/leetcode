class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        min_num = float('inf')
        mid_num = float('inf')
        for num in nums:
            if num <= min_num:
                min_num = num
            elif num < mid_num:
                mid_num = num
            elif num > mid_num:
                return True
        return False