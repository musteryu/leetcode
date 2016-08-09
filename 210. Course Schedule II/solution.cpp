#include <vector>
#include <utility>
using std::vector;
using std::pair;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> visited(numCourses);
        vector<bool> onStack(numCourses);
        vector<int> path;
        for (auto &relation: prerequisites) {
            graph[relation.first].push_back(relation.second);
        }
        for (int node = 0; node < numCourses; node++) {
            if (!visited[node] && dfs(graph, node, visited, onStack, path))
                return vector<int>();
        }
        return path;
    }
private:
    bool dfs(vector<vector<int>> &graph, int node, vector<bool> &visited, vector<bool> &onStack, vector<int> &path) {
        if (visited[node]) return false;
        onStack[node] = visited[node] = true;
        for (auto &neighbor: graph[node])
            if (onStack[neighbor] || dfs(graph, neighbor, visited, onStack, path))
                return true;
        onStack[node] = false;
        path.push_back(node);
        return false;
    }
};