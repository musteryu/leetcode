class Solution(object):

    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        if z > x + y:
            return False
        if z == x and z == y:
            return True
        return z % self.gcd(x, y) == 0

    def gcd(self, a, b):
        while b != 0:
            temp = b
            b = a % b
            a = temp
        return a
