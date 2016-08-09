#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> backtrack;
        res = vector<vector<int>>();
        dfs(backtrack, k, n);
        return res;
    }
private:
    vector<vector<int>> res;
    void dfs(vector<int>& backtrack, int leftNum, int leftSum) {
        // cout << leftNum << ", " << leftSum << endl;
        if (leftNum == 0 && leftSum == 0) res.push_back(backtrack);
        if (leftNum == 0 || leftSum == 0) return;
        for (int leftStart = backtrack.empty() ? 1 : backtrack.back() + 1
            ; leftStart < 10 && leftStart * leftNum <= leftSum
            ; leftStart++) {
            backtrack.push_back(leftStart);
            dfs(backtrack, leftNum-1, leftSum-leftStart);
            backtrack.pop_back();
        }
    }
};

auto main() -> int {
    Solution s;
    auto res = s.combinationSum3(2, 18);
    for (auto &r: res) {
        for (auto &i: r)
            cout << i << " ";
        cout << endl;
    }
}