class Solution(object):

    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        i = 0
        j = 0
        m = len(nums1)
        n = len(nums2)
        leftPart = []

        # cornor case

        if m == 0 and n == 0:
            return 0.0
        if m == 0 and n != 0:
            if n % 2 == 0:
                return (nums2[n / 2] + nums2[n / 2 - 1]) / 2.0
            else:
                return nums2[n / 2]
        if m != 0 and n == 0:
            if m % 2 == 0:
                return (nums1[m / 2] + nums1[m / 2 - 1]) / 2.0
            else:
                return nums1[m / 2]

        while len(leftPart) <= (m + n) / 2:
            if i == m:
                leftPart.append(nums2[j])
                j += 1
            elif j == n:
                leftPart.append(nums1[i])
                i += 1
            elif nums1[i] < nums2[j]:
                leftPart.append(nums1[i])
                i += 1
            else:
                leftPart.append(nums2[j])
                j += 1
        if (m + n) % 2 == 0:
            return (leftPart[-1] + leftPart[-2]) / 2.0
        else:
            return leftPart[-1]

if __name__ == '__main__':
    nums1 = []

    nums2 = [2, 3]

    s = Solution()
    print s.findMedianSortedArrays(nums1, nums2)
