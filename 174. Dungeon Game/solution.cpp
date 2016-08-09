class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size(), col = dungeon[0].size();
        vector<int> need(col+1, INT_MAX);
        need[col-1] = 1;
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                need[j] = max(1, min(need[j], need[j+1]) - dungeon[i][j]);
            }
        }
        return need[0];
    }
};