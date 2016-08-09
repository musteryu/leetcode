class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        for (int i = 1; i * i <= n; i++)
            dp[i*i] = 1;
        for (int i = 2; i <= n; i++)
            for (int l = 1, r = i-1; l <= r; l++, r--)
                dp[i] = min(dp[i], dp[l] + dp[r]);
        return dp[n];
    }
};
