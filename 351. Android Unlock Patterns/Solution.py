class Solution(object):
    def numberOfPatterns(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        visited = [False] * 10
        visited[0] = True
        jump = map(lambda r: [0] * 10, [0] * 10)
        jump[1][3] = jump[3][1] = 2
        jump[3][9] = jump[9][3] = 6
        jump[9][7] = jump[7][9] = 8
        jump[7][1] = jump[1][7] = 4
        jump[2][8] = jump[8][2] = jump[4][6] = jump[6][4] = jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5
        res = 0
        for remain in range(m, n + 1):
            res += self.dfs(visited, 1, remain-1, jump) * 4
            res += self.dfs(visited, 2, remain-1, jump) * 4
            res += self.dfs(visited, 5, remain-1, jump)
        return res

    def dfs(self, visited, current, remain, jump):
        if remain < 0:
            return 0
        if remain == 0:
            return 1
        visited[current] = True
        res = 0
        for next_node in range(1, 10):
            if not visited[next_node] and visited[jump[current][next_node]]:
                res += self.dfs(visited, next_node, remain-1, jump)
        visited[current] = False
        return res
        