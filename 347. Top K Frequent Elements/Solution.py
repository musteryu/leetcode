import collections
import heapq

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        count = collections.defaultdict(int)
        for num in nums:
            count[num] += 1
        res, hp = [], []
        for n, c in count.items():
            heapq.heappush(hp, (c, n))
            if len(hp) > k:
                heapq.heappop(hp)
        return [ heapq.heappop(hp)[1] for i in range(k) ]
