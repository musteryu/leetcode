import collections

class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        dict1 = collections.defaultdict(int)
        dict2 = collections.defaultdict(int)
        for num in nums1:
            dict1[num] += 1
        for num in nums2:
            dict2[num] += 1
        res = []
        for num in dict1:
            if num in dict2:
                res += [num] * min(dict1[num], dict2[num])
        return res