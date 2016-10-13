class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        slist = list(s)
        vowels = ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')
        l, r = 0, len(s) - 1
        while l < r:
            if slist[l] not in vowels:
                l += 1
                continue
            if slist[r] not in vowels:
                r -= 1
                continue
            slist[l], slist[r] = slist[r], slist[l]
            l += 1
            r -= 1
        return ''.join(slist)
