class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> counts(amount+1, amount+1);
        counts[0] = 0;
        for (auto &coin: coins) {
            for (int i = coin; i <= amount; i++) {
                counts[i] = min(counts[i], counts[i-coin] + 1);
            }
        }
        return counts[amount] < amount + 1 ? counts[amount] : -1;
    }
};