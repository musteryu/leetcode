public class Solution {
    private boolean dfs(boolean[] marked, 
            ArrayList<HashSet<Integer>> graph,
            int lastNode,
            int node) {
        if (marked[node]) return false;
        marked[node] = true;
        for (int neighbor: graph.get(node)) {
            if (neighbor == lastNode) continue;
            if (!dfs(marked, graph, node, neighbor)) return false;
        }
        return true;
    }
    public boolean validTree(int n, int[][] edges) {
        boolean[] marked = new boolean[n];
        ArrayList<HashSet<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            graph.add(new HashSet<Integer>());
        }
        
        for (int[] edge: edges) {
            int e0 = edge[0], e1 = edge[1];
            if (graph.get(e0).contains(e1) || graph.get(e1).contains(e0))
                return false;
            graph.get(e0).add(e1);
            graph.get(e1).add(e0);
        }
        if (!dfs(marked, graph, -1, 0)) return false;
        for (boolean m: marked)
            if (!m) return false;
        return true;
    }
}

public class Solution {
    class UnionFind {
        int[] root;
        int[] rank;
        int n;
        UnionFind(int n) {
            root = new int[n];
            rank = new int[n];
            this.n = n;
            for (int i = 0; i < n; ++i)
                root[i] = i;
        }

        int find(int x) {
            if (x != root[x]) {
                root[x] = find(root[x]);
            }
            return root[x];
        }

        boolean union(int x, int y) {
            int X = find(x), Y = find(y);
            if (X == Y) return true;
            else if (rank[X] > rank[Y]) 
                root[Y] = X;
            else if (rank[X] < rank[Y])
                root[X] = Y;
            else {
                root[Y] = X;
                ++rank[X];
            }
            --n;
            return false;
        }
    }

    public boolean validTree(int n, int[][] edges) {
        UnionFind uf = new UnionFind(n);
        for (int[] edge: edges) {
            int e0 = edge[0], e1 = edge[1];
            if (uf.union(e0, e1)) return false;
        }
        return uf.n == 1;
    }
}