class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return vector<int> {0};
        vector<vector<int>> graph(n);
        vector<int> degree(n);
        for (auto &edge: edges) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
            degree[edge.first]++;
            degree[edge.second]++;
        }
        queue<int> curr_level;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                curr_level.push(i);
            }
        }
        vector<int> res;
        while (curr_level.size()) {
            queue<int> next_level;
            int sz = curr_level.size();
            for (int i = 0; i < sz; i++) {
                int node = curr_level.front();
                curr_level.pop();
                degree[node]--;
                if (n <= 2)
                    res.push_back(node);
                for (auto &next_node: graph[node]) {
                    if (--degree[next_node] == 1) {
                        next_level.push(next_node);
                    }
                }
            }
            curr_level = std::move(next_level);
            n -= sz;
        }
        return res;
    }
};