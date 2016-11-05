import operator
import bisect

class Solution(object):
    def maxSumSubmatrix(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        rows, cols = len(matrix), len(matrix[0])
        row_is_outer, outers, inners = (True, rows, cols) if rows < cols else (False, cols, rows)
        max_sum = float('-inf')
        for l in range(0, outers):
            sums = [0] * inners
            for r in range(l, outers):
                sums = map(operator.add, sums, self.matrix_slice(matrix, r, row_is_outer))
                max_sum = max(max_sum, self.maxSumSubarray(sums, k))
        return max_sum
        
    def maxSumSubarray(self, sums, k):
        sum_set = [0, float('inf')]
        curr_sum, max_sum = 0, float('-inf')
        for s in sums:
            curr_sum += s
            i = bisect.bisect_left(sum_set, curr_sum - k)
            max_sum = max(curr_sum - sum_set[i], max_sum)
            bisect.insort(sum_set, curr_sum)
        return max_sum
    
    def matrix_slice(self, matrix, i, row_is_outer):
        if row_is_outer:
            return matrix[i]
        else:
            return [r[i] for r in matrix]
