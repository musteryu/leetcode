class Solution(object):

    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        slen, plen, j = len(s), len(p), 0
        matchs = [False] * (slen + 1)
        matchs[0] = True
        while j < plen:
            if j + 1 < plen and '*' == p[j + 1]:
                for i in xrange(slen + 1):
                    if not matchs[i] \
                            and i != 0 and matchs[i - 1] \
                            and ('.' == p[j] or p[j] == s[i - 1]):
                        matchs[i] = True
                j += 2
            else:
                for i in xrange(slen, -1, -1):
                    if i != 0 \
                            and matchs[i - 1] \
                            and ('.' == p[j] or p[j] == s[i - 1]):
                        matchs[i] = True
                    else:
                        matchs[i] = False
                j += 1
        return matchs[slen]

if __name__ == '__main__':
    so = Solution()
    f = open('test.txt', 'r')
    for line in f:
        tests, testp = line.split(' ')
        testp = testp[:-1] if testp[-1] == '\n' else testp
        print so.isMatch(tests, testp)
