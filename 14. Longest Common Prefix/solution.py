class Solution(object):

    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ''
        for i in range(len(strs[0])):
            for s in strs:
                if i >= len(s) or s[i] != strs[0][i]:
                    return strs[0][:i]
        return strs[0]

if __name__ == '__main__':
    so = Solution()
    teststrs = ["", "hell", "helloworld", "helloworl",
                "hellowor", "hellowo", "hellow", "hello"]
    print so.longestCommonPrefix(teststrs)
