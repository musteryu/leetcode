class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int hold = -prices[0], unhold = 0, freeze = INT_MIN;
        for (int i = 1; i < prices.size(); i++) {
            int prehold = hold;
            hold = max(hold, unhold - prices[i]);
            unhold = max(unhold, freeze);
            freeze = prehold + prices[i];
        }
        return max(unhold, freeze);
    }
};