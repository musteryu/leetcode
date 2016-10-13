class MovingAverage(object):

    def __init__(self, size):
        """
        Initialize your data structure here.
        :type size: int
        """
        self.queue = []
        self.max_size = size
        self.sum = 0

    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        self.sum += val
        self.queue.append(val)
        if len(self.queue) > self.max_size:
            first = self.queue[0]
            self.queue.pop(0)
            self.sum -= first
        return float(self.sum) / float(len(self.queue))


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)