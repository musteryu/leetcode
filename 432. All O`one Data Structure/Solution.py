class AllOne(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.kcnt = collections.defaultdict(int)
        self.kset = [set()]

    def inc(self, key):
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        :type key: str
        :rtype: void
        """
        self.kcnt[key] += 1
        cnt = self.kcnt[key]
        if cnt >= len(self.kset):
            self.kset.append(set())
        self.kset[cnt].add(key)
        if cnt - 1 > 0:
            self.kset[cnt - 1].remove(key)

    def dec(self, key):
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        :type key: str
        :rtype: void
        """
        self.kcnt[key] -= 1
        cnt = self.kcnt[key]
        if key in self.kset[cnt + 1]:
            self.kset[cnt + 1].remove(key)
        if cnt <= 0:
            del self.kcnt[key]
        else:
            self.kset[cnt].add(key)
        if len(self.kset) > 1 and len(self.kset[-1]) == 0:
            self.kset.pop()

    def getMaxKey(self):
        """
        Returns one of the keys with maximal value.
        :rtype: str
        """
        if len(self.kset) <= 1:
            return ""
        else:
            for k in self.kset[-1]:
                return k

    def getMinKey(self):
        """
        Returns one of the keys with Minimal value.
        :rtype: str
        """
        if len(self.kset) <= 1:
            return ""
        else:
            for k in self.kset[1]:
                return k


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()
