class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        totalLen = len(s)
        charDict = {}
        maxLen = 0
        begin = 0
        cursor = 0
       # import ipdb;
       # ipdb.set_trace()
        while cursor < totalLen:
            char = s[cursor]
            if char in charDict: # repeat
                curLen = cursor - begin
                if curLen > maxLen:
                    maxLen = curLen
                # if repeated char position is at the right of begin,
                # replace begin with the next position of repeated char.
                if charDict[char] >= begin:
                    begin = charDict[char] + 1
                charDict[char] = cursor
                cursor += 1
            else:
                charDict[char] = cursor
                cursor += 1

        curLen = cursor - begin
        if curLen > maxLen:
            maxLen = curLen
         
        return maxLen

if __name__ == '__main__':
    s = Solution()
    filename = "test/test.txt"
    with open(filename, 'r') as f:
        for line in f:
            if line[-1] == '\n':
                line = line[:-1]
            print s.lengthOfLongestSubstring(line)
