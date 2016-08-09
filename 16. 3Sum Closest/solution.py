class Solution(object):

    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        numsLen = len(nums)
        import sys
        currNearestDistance = sys.maxint

        for fst in range(numsLen):
            if fst > 0 and nums[fst] == nums[fst - 1]:
                continue
            snd = fst + 1
            trd = numsLen - 1
            while snd < trd:
                if snd > fst + 1 and nums[snd] == nums[snd - 1]:
                    snd += 1
                    continue
                if trd < numsLen - 1 and nums[trd] == nums[trd + 1]:
                    trd -= 1
                    continue
                currSum = nums[fst] + nums[snd] + nums[trd]
                if currSum == target:
                    return currSum
                if abs(target - currSum) < currNearestDistance:
                    currNearest = currSum
                    currNearestDistance = abs(target - currSum)
                if currSum > target:
                    trd -= 1
                else: # currSum < target:
                    snd += 1
        return currNearest


if __name__ == '__main__':
    so = Solution()
    testnums = [0, 0, 0]
    testtarget = 1
    print so.threeSumClosest(testnums, testtarget)
