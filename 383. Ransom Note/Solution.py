class Solution(object):

    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        maga = collections.defaultdict(int)
        for m in magazine:
            maga[m] += 1
        for r in ransomNote:
            maga[r] -= 1
            if maga[r] < 0:
                return False
        return True
