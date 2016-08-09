class Solution(object):

    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        intv = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        romv = ["M", "CM", "D", "CD", "C", "XC",
                "L", "XL", "X", "IX", "V", "IV", "I"]
        result = ''
        for i, v in enumerate(intv):
            if num >= v:
                time = num / v
                num -= time * v
                result += time * romv[i]
        return result


if __name__ == '__main__':
    so = Solution()
    test_nums = [1, 2, 3, 4, 5, 6, 9, 10, 11, 40, 41, 50, 51, 90,
                 91, 100, 101, 400, 401, 500, 501, 900, 901, 1000, 1001, 2015]
    for test_num in test_nums:
        print so.intToRoman(test_num)
