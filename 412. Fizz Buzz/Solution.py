class Solution(object):

    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def fzbz(n):
            if n % 5 == 0 and n % 3 == 0:
                return "FizzBuzz"
            if n % 5 == 0:
                return "Buzz"
            if n % 3 == 0:
                return "Fizz"
            return str(n)
        fb = xrange(1, n + 1)
        return list(map(fzbz, fb))
