import collections

class HitCounter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.hits = collections.OrderedDict()
        self.count = 0

    def hit(self, timestamp):
        """
        Record a hit.
        @param timestamp - The current timestamp (in seconds granularity).
        :type timestamp: int
        :rtype: void
        """
        hit = self.hits.get(timestamp, 0)
        self.hits[timestamp] = hit + 1
        self.count += 1

    def getHits(self, timestamp):
        """
        Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity).
        :type timestamp: int
        :rtype: int
        """
        limit = timestamp - 300
        dellist = []
        for i in self.hits:
            if i <= limit:
                self.count -= self.hits[i]
                dellist.append(i)
            else:
                break
        for to_del in dellist:
            del self.hits[to_del]
        return self.count

# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)