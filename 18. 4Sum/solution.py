class Solution(object):

    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        numsLen = len(nums)
        result = []

        for i in range(numsLen - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, numsLen - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                if nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target:
                    break
                if nums[i] + nums[j] + nums[numsLen - 2] + \
                        nums[numsLen - 1] < target:
                    continue
                k = j + 1
                l = numsLen - 1
                while k < l:
                    if k > j + 1 and nums[k] == nums[k - 1]:
                        k += 1
                        continue
                    if l < numsLen - 1 and nums[l] == nums[l + 1]:
                        l -= 1
                        continue
                    fsum = nums[i] + nums[j] + nums[k] + nums[l]
                    if fsum > target:
                        l -= 1
                    elif fsum < target:
                        k += 1
                    else:  # fsum == target
                        result.append([nums[i], nums[j], nums[k], nums[l]])
                        k += 1

        return result

if __name__ == '__main__':
    so = Solution()
    testnums = [-3,-2,-1,0,0,1,2,3]
    testtarget = 0
    print so.fourSum(testnums, 0)
