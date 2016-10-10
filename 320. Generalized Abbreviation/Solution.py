class Solution(object):
    def generateAbbreviations(self, word):
        """
        :type word: str
        :rtype: List[str]
        """
        length = len(word)
        res = ['' if length == 0 else str(length)]
        for i in range(0, length):
            for right in self.generateAbbreviations(word[i+1:]):
                leftNum = str(i) if i > 0 else ''
                res.append(leftNum + word[i:i+1] + right)
        return res
    