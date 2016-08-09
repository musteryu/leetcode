#include <vector>
#include <utility>
#include <queue>
using std::vector;
using std::pair;
using std::queue;


// dfs
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> marked(numCourses, false);
        vector<bool> onStack(numCourses, false);
        for (auto &relation: prerequisites) {
            graph[relation.first].push_back(relation.second);
        }
        for (int i = 0; i < numCourses; i++)
            if (!marked[i] && hasCycle(graph, marked, i, onStack))
                return false;
        return true;
    }
private:
    bool hasCycle(vector<vector<int>> &graph, vector<bool> &marked, int node, vector<bool> &onStack) {
        if (marked[node]) return false;
        onStack[node] = true;
        marked[node] = true;
        for (int &to: graph[node]) {
            if (onStack[to] || hasCycle(graph, marked, to, onStack))
                return true;
        }
        return onStack[node] = false;
    }
};

// bfs
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegrees(numCourses, 0);
        for (auto &relation: prerequisites) {
            graph[relation.first].push_back(relation.second);
        }
        computeDegree(graph, inDegrees);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!inDegrees[j]) {
                    for (auto &neighbor: graph[j])
                        inDegrees[neighbor]--;
                    inDegrees[j] = -1;
                    break;
                }
            }
            if (j == numCourses) return false;
        }
        return true;
    }
private:
    void computeDegree(vector<vector<int>> &graph, vector<int> &inDegrees) {
        for (auto &neighbors: graph) {
            for (auto &n: neighbors) {
                inDegrees[n]++;
            }
        }
    }
};