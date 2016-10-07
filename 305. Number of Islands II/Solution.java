public class Solution {
    private int[] root;
    private int m;
    private int n;
    private static int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    public List<Integer> numIslands2(int m, int n, int[][] positions) {
        UnionFind islands = new UnionFind(m, n);
        List<Integer> res = new LinkedList<Integer>();
        for (int[] position: positions) {
            int r = position[0], c = position[1];
            int p = islands.add(r, c);
            for (int[] d : dirs) {
                int q = islands.getID(r+d[0], c+d[1]);
                if (q != -1 && !islands.find(p, q))
                    islands.unite(p, q);
            }
            res.add(islands.size());
        }
        return res;
    }
}
class UnionFind {
    private int[] id;
    private int[] sz;
    private int m, n, count;

    public UnionFind(int m_, int n_) {
        m = m_;
        n = n_;
        id = new int[m*n];
        sz = new int[m*n];
        Arrays.fill(id, -1);
        count = 0;
    }

    private int index(int i, int j) {
        return j + i * n;
    }

    public int getID(int i, int j) {
        if (i >= 0 && i < m && j >= 0 && j < n)
            return id[index(i, j)];
        return -1;
    }

    public int size() {
        return count;
    }

    public boolean find(int p, int q) {
        return root(p) == root(q);
    }

    public int add(int i, int j) {
        int p = index(i, j);
        id[p] = p;
        sz[p] = 1;
        ++count;
        return p;
    }

    private int root(int p) {
        if (id[p] == p) return p;
        return id[p] = root(id[p]);
    }

    public void unite(int p, int q) {
        p = root(p);
        q = root(q);
        if (sz[p] < sz[q]) {
            id[p] = q;
            sz[q] += sz[p];
        } else {
            id[q] = p;
            sz[p] += sz[q];
        }
        count--;
    }
}