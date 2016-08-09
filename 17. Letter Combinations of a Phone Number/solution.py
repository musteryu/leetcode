class Solution(object):

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        letterMapTable = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
                          '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        letters = []

        for d in digits:
            tmp = []
            if letters == []:
                for newletter in letterMapTable[d]:
                    tmp.append(newletter)
            else:
                for letters in letters:
                    for newletter in letterMapTable[d]:
                        tmp.append(letters + newletter)
            letters = tmp

        return letters
        

if __name__ == '__main__':
    so = Solution()
    testdigits = '74343'
    print so.letterCombinations(testdigits)
