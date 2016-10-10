class Solution(object):
    def countComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        union_find = UnionFind(n)
        for (e1, e2) in edges:
            union_find.union(e1, e2)
        return union_find.parts()

class UnionFind(object):
    def __init__(self, n):
        self.rt = range(n)
        self.sz = [1] * n
        self.count = 0
    
    def root(self, p):
        if self.rt[p] == p:
            return p
        self.rt[p] = self.root(self.rt[p])
        return self.rt[p]

    def union(self, p, q):
        prt = self.root(p)
        qrt = self.root(q)
        if self.sz[prt] < self.sz[qrt]:
            self.rt[prt] = self.rt[qrt]
            self.sz[qrt] += self.sz[prt]
        else:
            self.rt[qrt] = self.rt[prt]
            self.sz[prt] += self.sz[qrt]
    
    def parts(self):
        p = 0
        for i in range(len(self.rt)):
            if i == self.rt[i]:
                p += 1
        return p