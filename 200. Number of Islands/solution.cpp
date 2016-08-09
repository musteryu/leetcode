#include <vector>
using std::vector;


// using union find
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int row = grid.size(), col = grid[0].size();
        vector<int> union_find(row * col, -1);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1') {
                    union_find[i * col + j] = i * col + j;
                    if (i > 0 && grid[i-1][j] == '1') {
                        int root = (i - 1) * col + j;
                        while (union_find[root] != root) {
                            root = union_find[root];
                        }
                        union_find[root] = i * col + j;
                    }
                    if (j > 0 && grid[i][j-1] == '1') {
                        int root = i * col + j - 1;
                        while (union_find[root] != root) {
                            root = union_find[root];
                        }
                        union_find[root] = i * col + j;
                    }
                }
            }
        }
        int cnt = 0;
        for (int idx = 0; idx < row * col; idx++) {
            if (union_find[idx] == idx) cnt++;
        }
        return cnt;
    }
};

// using bfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        vector<vector<bool>> marked(row, vector<bool>(col));
        int cnt = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1' && !marked[i][j]) {
                    marked[i][j] = true;
                    queue<int> q;
                    q.push(i * col + j);
                    while (!q.empty()) {
                        int qLen = q.size();
                        for (int _i = 0; _i < qLen; _i++) {
                            int idx = q.front();
                            q.pop();
                            int rowIdx = idx / col;
                            int colIdx = idx % col;
                            if (rowIdx > 0 && grid[rowIdx - 1][colIdx] == '1' && !marked[rowIdx - 1][colIdx]) {
                                q.push(idx - col);
                                marked[rowIdx-1][colIdx] = true;
                            }
                            if (rowIdx < row - 1 && grid[rowIdx + 1][colIdx] == '1' && !marked[rowIdx + 1][colIdx]) {
                                q.push(idx + col);
                                marked[rowIdx+1][colIdx] = true;
                            }
                            if (colIdx > 0 && grid[rowIdx][colIdx - 1] == '1' && !marked[rowIdx][colIdx - 1]) {
                                q.push(idx - 1);
                                marked[rowIdx][colIdx-1] = true;
                            }
                            if (colIdx < col - 1 && grid[rowIdx][colIdx + 1] == '1' && !marked[rowIdx][colIdx + 1]) {
                                q.push(idx + 1);
                                marked[rowIdx][colIdx+1] = true;
                            }
                        }
                    }
                    cnt++;
                }
            }
        }
        return cnt;
    }
};