import bisect

class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        envelopes.sort(cmp = lambda a, b: cmp((a[0], b[1]), (b[0], a[1])))
        tails = []
        for i, (w, h) in enumerate(envelopes):
            index = bisect.bisect_left(tails, h)
            if index >= len(tails):
                tails.append(h)
            else:
                tails[index] = h
        return len(tails)
