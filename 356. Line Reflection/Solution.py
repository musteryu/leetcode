class Solution(object):
    def isReflected(self, points):
        """
        :type points: List[List[int]]
        :rtype: bool
        """
        if not points:
            return True
        xs = [x for x, y in points]
        min_x, max_x = min(xs), max(xs)
        ref_line = min_x + max_x
        point_set = set([(x, y) for x, y in points])
        for x, y in point_set:
            ref_x, ref_y = ref_line - x, y
            if (ref_x, ref_y) not in point_set:
                return False
        return True
        