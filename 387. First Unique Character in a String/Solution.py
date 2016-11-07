class Solution(object):

    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        candidate = {}
        noconsider = set()

        for i, c in enumerate(s):
            if c not in candidate and c not in noconsider:
                candidate[c] = i
            elif c in candidate:
                del candidate[c]
                noconsider.add(c)
        return -1 if not candidate else candidate[min(candidate, key=lambda k: candidate[k])]
