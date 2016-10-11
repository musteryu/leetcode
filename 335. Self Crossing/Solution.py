class Solution(object):
    def isSelfCrossing(self, x):
        """
        :type x: List[int]
        :rtype: bool
        """
        xlen = len(x)
        if xlen < 4:
            return False
        for i in range(3, xlen):
            if x[i] >= x[i-2] and x[i-1] <= x[i-3]:
                return True
            if i >= 4 and x[i-1] == x[i-3] and x[i] + x[i-4] >= x[i-2]:
                return True
            if i >= 5 and x[i] + x[i-4] >= x[i-2] and \
                x[i-1] + x[i-5] >= x[i-3] and \
                x[i-1] <= x[i-3] and \
                x[i-4] <= x[i-2]:
                return True
        return False

if __name__ == '__main__':
    print Solution().isSelfCrossing([1,2,3,4])

        
