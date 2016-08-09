#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <functional>
using namespace std;


/* to slow
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        set<int> xSet;
        for (auto& coord: buildings) {
            xSet.insert(coord[0]);
            xSet.insert(coord[1]);
        }
        vector<int> xVec(xSet.begin(), xSet.end());
        map<int, int> xMap;
        for (int idx = 0; idx < xVec.size(); idx++) {
            xMap.insert(pair<int, int>(xVec[idx], idx));
        }
        vector<int> yVec(xVec.size(), 0);
        for (auto& coord: buildings) {
            int beginIdx = xMap[coord[0]];
            int endIdx = xMap[coord[1]];
            for (int idx = beginIdx; idx < endIdx; ++idx) {
                yVec[idx] = max(coord[2], yVec[idx]);
            }
        }
        vector<pair<int, int>> keyPoints;
        for (int idx = 0; idx < yVec.size(); idx++) {
            int y = yVec[idx];
            int x = xVec[idx];
            if (keyPoints.empty() || y != keyPoints.back().second)
                keyPoints.push_back(pair<int, int>(x, y));
        }
        return keyPoints;
    }
};*/

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> edges;
        edges.reserve(buildings.size() * 2);
        for (auto& building: buildings) {
            int left = building[0];
            int right = building[1];
            int height = building[2];
            edges.push_back(make_pair(left, -height));
            edges.push_back(make_pair(right, height));
        }
        std::sort(edges.begin(), edges.end());
        vector<pair<int, int>> result;
        multiset<int> maxHeight;
        maxHeight.insert(0);
        int lastMax = 0, currMax = 0;
        for (auto& edge: edges) {
            if (edge.second < 0)
                maxHeight.insert(-edge.second);
            else
                maxHeight.erase(maxHeight.find(edge.second));
            currMax = *maxHeight.rbegin();
            if (currMax != lastMax) {
                result.push_back(make_pair(edge.first, currMax));
                lastMax = currMax;
            }
        }
        return result;
    }
};

auto main() -> int {
    Solution s;
    vector<vector<int>> buildings = {
        {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}
    };
    vector<pair<int, int>> keyPoints = s.getSkyline(buildings);
    for (auto& keyPoint: keyPoints) {
        cout << "(" << keyPoint.first << "," << keyPoint.second << ") " << endl;
    }
}