class Solution(object):

    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]

        For example, given array S = {-1 0 1 2 -1 -4},

        A solution set is:
        (-1, 0, 1)
        (-1, -1, 2)
        """
        nums.sort()
        numsLen = len(nums)
        result = []
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
                sum = nums[fst] + nums[snd] + nums[trd]
                if sum > 0:
                    trd -= 1
                elif sum < 0:
                    snd += 1
                else:
                    result.append([nums[fst], nums[snd], nums[trd]])
                    snd += 1
        return result

if __name__ == '__main__':
    so = Solution()
    nums = [-2, 0, 1, 1, 2]
    print so.threeSum(nums)
