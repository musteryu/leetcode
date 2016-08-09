import sys

class Solution(object):

    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        end = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[end]:
                nums[end+1], nums[i], end = nums[i], nums[end+1], end+1
        return end+1 if nums else 0

if __name__ == '__main__':
    f = open('test.txt', 'r')
    for line in f:

        testnums = eval(line)
        numsset = set(testnums)
        print len(numsset)
        print Solution().removeDuplicates(testnums)
        # print numsset
        # print testnums
