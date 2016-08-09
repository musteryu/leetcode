/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var len = prices.length, buy = 0, sell, win = 0;
    while (buy < len - 1) {
        for (sell = buy + 1; sell < len; sell++) {
            if (prices[sell] > prices[sell-1]) {
                win += (prices[sell] - prices[sell-1])
            } else if (prices[sell] < prices[sell-1]) {
                break;
            }
        }
        buy = sell;
    }
    return win;
};