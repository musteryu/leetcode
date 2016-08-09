/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var len = prices.length, buy = 0, win = 0;
    for (var i = 0; i < len; i++) {
        if (prices[i] > prices[buy] && prices[i] - prices[buy] > win) {
            win = prices[i] - prices[buy];
        } else if (prices[i] < prices[buy]) {
            buy = i;
        }
    }
    return win;
};