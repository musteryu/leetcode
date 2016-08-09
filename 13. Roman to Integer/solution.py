class Solution(object):

    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        romanceDict = {"M": 1000, "CM": 900, "D": 500, "CD": 400, "C": 100,
                       "XC": 90, "L": 50, "XL": 40, "X": 10, "IX": 9, "V": 5,
                       "IV": 4, "I": 1}
        result = 0
        i = 0
        while i < len(s):
            if i < len(s) - 1 and s[i] + s[i + 1] in romanceDict:
                result += romanceDict[s[i] + s[i + 1]]
                i += 2
            else:
                result += romanceDict[s[i]]
                i += 1
        return result

if __name__ == '__main__':
    so = Solution()
    tests = 'MCMXCVI'
    print so.romanToInt(tests)
