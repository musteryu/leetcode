import collections


class Solution(object):
    def lengthOfLongestSubstringKDistinct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        d = collections.defaultdict(int)
        l, r, count, length = 0, 0, 0, 0
        while r <= len(s):
            if count <= k:
                length = max(length, r - l)
                if r == len(s):
                    break
                if d[s[r]] == 0:
                    count += 1
                d[s[r]] += 1
                r += 1
            else:
                d[s[l]] -= 1
                if d[s[l]] == 0:
                    count -= 1
                l += 1
        return length
