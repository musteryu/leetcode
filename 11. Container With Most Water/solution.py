class Solution(object):

    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i, j = 0, len(height) - 1
        maxarea = 0
        while i != j:
            if height[i] < height[j]:
                area, i, j = height[i] * (j - i), i+1, j
            else:
                area, i, j = height[j] * (j - i), i, j-1
            maxarea = area if area > maxarea else maxarea
        return maxarea

if __name__ == '__main__':
    so = Solution()
    f = open('test.txt', 'r')
    for line in f:
        testheight = eval(line)
        print "height  :", testheight
        print "max area:", so.maxArea(testheight)
