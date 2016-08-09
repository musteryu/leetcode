class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        maxbgn, maxend = 0, 0
        maxlen = 0
        # import ipdb
        # ipdb.set_trace()
        if len(s) == 1:
            return s

        # for abba
        for bgn in range(len(s) - 1):
            end = bgn + 1
            while bgn >= 0 and end < len(s) and s[bgn] == s[end]:
                bgn, end = bgn-1, end+1
            if end - bgn - 1 > maxlen:
                maxlen = end - bgn - 1
                maxbgn = bgn + 1
                maxend = end - 1

        # for abcba
        for bgn in range(len(s) - 1):
            end = bgn + 2
            while bgn >= 0 and end < len(s) and s[bgn] == s[end]:
                bgn, end = bgn-1, end+1
            if end - bgn - 1 > maxlen:
                maxlen = end - bgn - 1
                maxbgn = bgn + 1
                maxend = end - 1
        if maxbgn == 0 and maxend == 0:
            return ""
        else:
            return s[maxbgn : maxend + 1]
        

                



if __name__ == '__main__':
    solution = Solution()
    with open("test.txt", 'r') as f:
        for line in f:
            if line[-1] == "\n":
                line = line[:-1]
            print solution.longestPalindrome(line)

        