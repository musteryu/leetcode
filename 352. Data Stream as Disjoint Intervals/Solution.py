# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class SummaryRanges(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.intervals = []

    def addNum(self, val):
        """
        :type val: int
        :rtype: void
        """
        intervals = self.intervals
        if not intervals:
            intervals.append(Interval(val, val))
        l, r = 0, len(self.intervals)
        if intervals[l].start == val + 1:
            intervals[l] = Interval(val, intervals[l].end)
            return
        if intervals[l].start > val:
            intervals.insert(l, Interval(val, val))
            return
        while l < r - 1:
            mid = (l + r) / 2
            if intervals[mid].start <= val:
                l = mid
            else:
                r = mid
        la, lb = intervals[l].start, intervals[l].end
        if la <= val <= lb:
            return
        if r < len(intervals):
            ra, rb = intervals[r].start, intervals[r].end
            if la + 1 == val and val + 1 < ra:
                intervals[l] = Interval(la, val)
            elif la + 1 < val and val + 1 == ra:
                intervals[r] = Interval(val, rb)
            elif la + 1 == val and val + 1 == ra:
                intervals[l] = Interval(la, rb)
                del intervals[r]
            else:
                intervals.insert(r, Interval(val, val))
        else:
            if la + 1 == val:
                intervals[l] = Interval(la, val)
            else:
                intervals.append(Interval(val, val))

    def getIntervals(self):
        """
        :rtype: List[Interval]
        """
        return self.intervals


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(val)
# param_2 = obj.getIntervals()