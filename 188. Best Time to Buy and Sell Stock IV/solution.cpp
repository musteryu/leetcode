class Solution {
private:
    int maxProfit(vector<int> & prices) {
        int col = prices.size(), profit = 0;
        for (int i = 1; i < col; i++) {
            if (prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        }
        return profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int col = prices.size();
        if (col == 0 || col == 1) return 0;
        if (k <= 0) return 0; 
        if (k > col / 2) return maxProfit(prices);
        vector<int> dp(col, 0);
        int lastMaxProfit = INT_MIN;
        int lastTmp = 0, currTmp = 0;
        for (int i = 0; i < k; i++) {
            int lastMost =  - prices[0];
            lastTmp = 0;
            for (int j = 1; j < col; j++) {
                currTmp = dp[j];
                dp[j] = max(dp[j-1], lastMost + prices[j]);
                lastMost = max(lastTmp - prices[j], lastMost);
                lastTmp = currTmp;
            }
            if (dp[col-1] == lastMaxProfit) return dp[col-1];
            lastMaxProfit = max(dp[col-1], lastMaxProfit);
        }
        return dp[col-1];
    }
};

// Java Solution using two dp arrays.
/**
public int maxProfit(int k, int[] prices) {
    if(k == 0 || prices.length < 2)
        return 0;
    if(k > prices.length / 2)
        return noLimit(prices);
    
    // hold[i][j]: For at most i transactions, the max profit on jth day with a stock in hand.
    // unhold[i][j]: For at most i transactions, the max profit on jth day without a stock in hand
    int[][] hold = new int[k+1][prices.length];
    int[][] unhold = new int[k+1][prices.length];
    for(int i = 1; i <= k; i++) {
        hold[i][0] = -prices[0];
        unhold[i][0] = 0;
        for(int j = 1; j < prices.length; j++) {
            hold[i][j] = Math.max(-prices[j] + unhold[i-1][j], hold[i][j-1]); // Buy or not buy
            unhold[i][j] = Math.max(prices[j] + hold[i][j-1], unhold[i][j-1]); // Sell or not sell
        }
    }
    return unhold[k][prices.length-1];
}
private int noLimit(int[] prices) { // Solution from Best Time to Buy and Sell Stock II
    int max = 0;
    for(int i = 0; i < prices.length-1; i++) {
        if(prices[i+1] > prices[i])
            max += prices[i+1] - prices[i];
    }
    return max;
}
**/