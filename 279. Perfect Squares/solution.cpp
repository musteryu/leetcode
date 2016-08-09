class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp { INT_MAX };
        static int max_root = 1;
        int old_size = dp.size();
        if (dp.size() <= n) {
            dp.resize(n+1);
        }
        for (int i = old_size; i <= n; i++)
            if (i == max_root * max_root) {
                dp[i] = 1;
                max_root++;
            } else {
                dp[i] = INT_MAX;
                for (int l = 1, r = i-1; l <= r; l++, r--)
                    dp[i] = min(dp[i], dp[l] + dp[r]);
            }
        return dp[n];
    }
};

